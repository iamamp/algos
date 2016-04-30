#include <stdio.h>

//checks if a tree is a subtree of another

typedef struct node
{
    struct node* lc;    //note while copy pasting cpp code to a c file,i HAD to add keyword 'struct' here!!
    struct node* rc;
    int data;
}node;

void recursive_preorder(node* p) //node-left-right,this is correct!!
{
    if(p!=NULL)
    {
        printf("%d\t",p->data);
        recursive_preorder(p->lc);
        recursive_preorder(p->rc);
    }
}

node* add_node(int data,node* root)//i wanna figure out a recursive fn for this! //EDIT this is a very crude way to create a tree
{
	node *temp,*p,*o;

    temp = (node*)malloc(sizeof(node));
    temp->data=data;
    temp->lc=NULL;
    temp->rc=NULL;

    if (root==NULL) root=temp;
	else
    {
        p=root;
        while(p!=NULL) //p may become null but 'o' will still be a valid data node
        {
            o=p; //o will be 1 step behind p

            if (data==p->data) return NULL;
            else if (data > p->data) p=p->rc;
            else if (data < p->data) p=p->lc;
        }
        if(data > o->data) o->rc=temp;   //MOST IMP THING IN WHOLE SECOND YR OF ENGG
        else               o->lc=temp;
    }
    return root;
}

int subtree(node *p1,node *p2)//PLZ FOR GODSAKES NEVER GO INTO DETAIL OF COMPARE FN AND SUBTREE FN SIMULTANEOULSY!
{
    if(p1) //bcoz we are using ONLY root node of p2. so we bother only with node of p1 being NULL or not
    {
        if(compare(p1,p2)) return 1;
        else return  subtree(p1->lc,p2) || subtree(p1->rc,p2) ;
    }
    else return 0; //NOTHING LEFT TO COMPARE TO,HAVE TO RET 0
}

// always remember that theres only 4 cases here
// 1) p1->data==p2->data
// 2) One is NULL other is not
// 3) Both are NULL
// 4) p1->data!=p2->data

int compare(node *p1,node *p2)//note that this is essentially preorder traversal,BCOZ OF THE STMT ON LINE 114***
{
    if(p1 && p2) //if structurally same
    {
        if(p1->data==p2->data) return( compare(p1->lc,p2->lc) && compare(p1->rc,p2->rc) );
        else return 0;
    }
    else if(!p1 && !p2) return 1; //the terminating cond
    else return 0;
}

void main()
{
    int n1,n2,data,i;
    node *p1=NULL,*p2=NULL;

    printf("enter num of nodes for tree 1\n"); //try to keep tree 1 bigger so that subtree fn will mk sense
    scanf("%d",&n1);

    for(i=0;i<n1;i++)
    {
        printf("enter data for node %d\n",i+1);
        scanf("%d",&data);
        p1=add_node(data,p1);
    }

    printf("\ndisplaying tree 1 in preorder\n");
    recursive_preorder(p1);

    printf("\n\nenter num of nodes for tree 2\n");
    scanf("%d",&n2);

    for(i=0;i<n2;i++)
    {
        printf("enter data for node %d\n",i+1);
        scanf("%d",&data);
        p2=add_node(data,p2);
    }

    printf("\ndisplaying tree 2 in preorder\n");
    recursive_preorder(p2);

    if(!compare(p1,p2)) printf("\n\ntheyre unequal man\n");
    else                printf("\n\ntheyre exactly equal!\n");

    if(!subtree(p1,p2)) printf("\ntree 2 inst a subtree of tree 1 man\n");
    else                printf("\ntree 2 is a subtree of tree 1!\n");
}


