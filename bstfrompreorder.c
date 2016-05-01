//btw this looks interesting
//ask interviewer to give you any preorder traversal

#include <stdio.h>  //consider 10 5 1 7 40 50
#define max 20      //btw i think this is EXACTLY same as constructing a BST from given input...DSF assignment 5 like!
int pre[max]={10,5,1,7,40,50};
//int hash[256]={0};
int i=0,n=6,mh=0;  //n is gnna be total num of nodes

typedef struct node
{
    int data;
    struct node* l;
    struct node* r;
}node;

node* makenode(node* p,int data)
{
    p=malloc(sizeof(node));
    p->data=data;
    p->l=NULL;
    p->r=NULL;
}

node* f(int mn,int mx) //the assumption is that all elements are strictly unique
{
    node *p=NULL;    //this is gnna be the return value,the head node for main tree,head node for other subtrees
    if (i==n) return NULL;

    if(pre[i]>=mn && pre[i]<=mx)//the equality would hold tree in case of the smallest/largest elements in the tree
    {
        p=makenode(p,pre[i]);
        i++;

        p->l=f(mn,pre[i-1]);  //first u go to the left and see if it fits the bill
        p->r=f(pre[i-1],mx);  //if not u go to the right
    }                       //if STILL NOT,u get out of the current call,and use line 28 to check for right side of parent
                            //the above 3 comment lines are extremely important!!***  //the mn and mx for a particular call are constant!
    return p;
}

void preorder(node* p)
{
    if(p)
    {
        printf("%3d",p->data);
        preorder(p->l);
        preorder(p->r);
    }
}

//by DEFINITION,height of a node is number of edges in path from node to a leaf***

int d(node* p) //epic //this d function is actually a height function!
{
    if (!p) return -1;
    if ( d(p->l) > d(p->r) ) return d(p->l)+1;  //the '+1' is where things are really adding up!!
    else                     return d(p->r)+1;
}

//function l will return length of longest leaf to leaf path in tree

void l(node *p)
{
    if(p)//start by considering as if ans is along the root
    {
        if( mh < d(p->l)+d(p->r)+2 )  mh = d(p->l)+d(p->r)+2;
        l(p->l);
        l(p->r);
    }
}

void main()
{
    int mn=255,mx=0,j=0;
    node *root=NULL;
    /*
    printf("enter num of elements\n");
    scanf("%d",&n);

    for(j=0;j<256;j++) hash[j]=0;

    for(j=0;j<n;j++)
    {
        scanf("%d",&pre[j]);
        if ( ++hash[pre[j]]>1 ) {printf("you damned fool\n"); return;}
        if (pre[j]>mx) mx=pre[j];
        if (pre[j]<mn) mn=pre[j];
    }
    */

    printf("\nyour input array was\n");
    for (j=0;j<n;j++) printf("%3d",pre[j]);
    //printf("\nmin and max are %d,%d\n",mn,mx);

    root=f(1,50);
    printf("\n\npreorder traversal of tree:\n");
    preorder(root);
    printf("\n\nheight of root node,in other words,height of tree is %d\n",d(root));
    l(root);
    printf("\nlength of longest leaf to leaf path is %d\n",mh);
}

/*---------------------------------------------------------------------------------------------------------------------

plain english explanation.....read this ITLL HELP INSTANTANEOUSLY

you have 10 5 1 7 40 50
EACH CALL AT EACH LEVEL HAS ITS MIN AND MAX ************



main calls f(1,50)    as they were the min and max from given array                                                                                              (point 0)
i=0  a[i]=10
NOW AT LEVEL 0.        NOTE : JUST ONE AND ONLY ONE CALL WAS MADE TO REACH LEVEL 0. LEVEL 0 ITSELF WILL MAKE TWO CALLS
min 1
max 50

10 is between 1 and 50 so place 10
you get:
                            level 0
                _________10________
               /                   \










                                    level 0 has the numbers 1 and 50,      (from 0)
                                    and right now, the element 10   (point 1)

so, AT LEVEL 0 two calls MAY be made,
                                        first with 10 as max FOR LEFT CHILD OF 10 : f(1,10) LEADING TO LEVEL 1.1,  (from 1)(point 2)
                                        second with 10 as min FOR RIGHT CHILD OF 10 : f(10,50) LEADING TO LEVEL 1.2     (from 1)(point 3)


so level 0 first calls f(1,10^) leading to level 1.1        ^denotes placed element
i=1  a[i]=5
NOW AT LEVEL 1.1 : left child of 10
min 1
MAX 10 (root node at level 0)

5 is between 1 and 10 so place 5
you get:

                    _________10________             //note 10 is at level 0
                __ /          |
level 1.1   __5               |
           /  |               |
              |               |








                                        REMEMBER THAT THIS LEVEL 1.1 HAS THE NUMBERS 1 AND 10,      (from 2)(10 happened to be a[i] in prev level 0)(point 4)
                                        and right now, the element 5                                (point 5)

next,AT LEVEL 1.1, two calls MAY be made,
                                        first with 5 as max FOR LEFT CHILD OF 5 : f(1,5) LEADING TO LEVEL 2.1,  (from 5)(point 6)
                                        second with 5 as min FOR RIGHT CHILD OF 5 : f(5,10) LEADING TO LEVEL 2.2    (from 5 and 4)(point 7)


so level 1.1 first calls f(1,5^) leading to level 2.1
i=2  a[i]=1
NOW AT LEVEL 2.1 : left child of 5
min 1
MAX 5 (root node at level 1)

1 is between 1 and 5 so place 1 (we are using >=,<=)
you get:

                    _________10________
                __ /          |
            __5               |
           /  |               |
 lvl2.1   1   |               |









                                        REMEMBER THAT THIS LEVEL 2.1 HAS THE NUMBERS 1 AND 5,      (from 6)(5 happened to be a[i] in prev level 1)(point 8)
                                        and right now, the element 1                                (point 9)

next, IN LEVEL 2.1, two calls MAY be made,
                                        first with 1 as max FOR LEFT CHILD OF 1 : f(1,1^) LEADING TO LEVEL 3.1,   (from 9)(point 10)
                                        second with 1 as min FOR RIGHT CHILD OF 1 : f(1^,5) LEADING TO LEVEL 3.2  (from 9 and 8)(point 11)


so, level 2.1 first calls f(1,1^) leading to level 3.1
i=3  a[i]=7
NOW AT LEVEL 3.1 : left child of 1
min 1
MAX 1 (root node at level 2.1)


7 is NOT between 1 and 1^, so YOU IMM EXIT LEVEL 3.1. YOU ARE BACK TO LEVEL 2.1, AND ARE GNNA MAKE RIGHT CALL TO LEVEL 3.2!

                _________10________
               /
             _5
            /
           1 level 2.1
          /


so instead, level 2.1 calls f(1^,5) leading to level 3.2
i=3  a[i]=7
NOW AT LEVEL 3.2 : right child of 1
MIN 1 (root node at level 2.1)
max 5 (root node at level 1.1)


AND NEITHER IS 7 BETWEEN 1^ and 5. SO YOU IMM EXIT 3.2 AND ARE BACK TO 2.1. WHERE ENDING CURLY BRACE IS REACHED AND YOU GO BACK TO 1.1 TO CHECK 2.2

so, level 1.1 THEN calls f(5^,10) leading to level 2.2
i=3 a[i]=7
NOW AT LEVEL 2.2 : right child of 5
MIN 5 (root node at level 1.1)
max 10 (root node at level 0)

PLACE 7!!!










THE ONLY RULE I SEE IS THAT LEAVING LEVEL 0,EACH LEVEL GETS ONE OF THEM FROM PREVIOUS LEVEL ROOT ELEMENT. THE OTHER ONE IS INHERITED FROM ABOVE
OFC, LEVEL 0 GETS BOTH FROM MAIN


*/
