#include <stdio.h>
#define max 20
int pre[max]={10,5,1,7,40,50};
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

node* f(int mn,int mx)
{
    node *p=NULL;
    if (i==n) return NULL;

    if(pre[i]>=mn && pre[i]<=mx)
    {
        p=makenode(p,pre[i]);
        i++;

        p->l=f(mn,pre[i-1]);
        p->r=f(pre[i-1],mx);
    }

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

//WHAT YOU GOTTA REMEMBER HERE IS A PLUS ONE

int d(node* p) //epic //this d function is actually a height function!
{
    if (!p)                  return -1;
    if ( d(p->l) > d(p->r) ) return d(p->l)+1;  //the '+1' is where things are really adding up!!
    else                     return d(p->r)+1;
}

/*

plain english explanation

if you are at a null ptr return -1
if you had just one node,which was the root, with no leaves,
    (call to left child which is null) + 1      is  -1 + 1 = 0
    (call to right child which is null) + 1     is   -1 + 1 = 0

so a lone root node return 0

what if a root node has a single left child ?(or a single right child     OR   BOTH!)
(call to that child) + 1    would be returned   which is 0 + 1 = 1

and so on

THIS CAN ALSO BE USED TO CHECK IF BT IS BALANED OR NOT!

make a check with your children...and pass the result above after adding ONE to it

3 FKIN LINES

*/

void main()
{
    int mn=255,mx=0,j=0;
    node *root=NULL;

    printf("\nyour input array was\n");
    for (j=0;j<n;j++) printf("%3d",pre[j]);

    root=f(1,50);
    printf("\n");
    preorder(root);
    printf("\nheight of root node,in other words,height of tree is %d\n",d(root));
}
