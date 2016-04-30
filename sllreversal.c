#include <stdio.h>
/*
if u have to reverse an LL within chunks of k nodes then do this:
go to every kth node,and break the link.
apply r2 api from 1st node of chunk till breakpoint
reattach
*/

typedef struct node{
    int data;
    struct node* next;
}node;

node* head=NULL;

void r1(node* p)
{
    if(p->next==NULL)
    {
        head=p;
        return;
    }
    r1(p->next);
    p->next->next=p;
    p->next=NULL; //the 'next' link will now poke out of its other end
                    //im thinking this line will be of full use only at the end of first call....when head is supposed to be tail and pointing to null
                    //code can be changed slightly to fix it
}

void r2()
{
    node *current=head;
    node *nxt=head->next;
    node *prev=NULL;

    while(current)
    {
        current->next=prev;
        prev=current;
        current=nxt;
        if(nxt) nxt=nxt->next;
    }
    head=prev;
}

void d(node* p)
{
    printf("\n");
    while(p)
    {
        printf("%3d",p->data);
        p=p->next;
    }
}

void main()
{
    int n,i=0;
    node* p=NULL;
    printf("enter num of nodes\n");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        if(!head)
        {
            head=malloc(sizeof(node));
            head->next=NULL;
            head->data=i;
            p=head;     //make p the node u just added
        }
        else
        {
            p->next=malloc(sizeof(node));
            p->next->next=NULL;
            p->next->data=i;
            p=p->next;  //make p the node u just added
        }
    }

    d(head);
    r1(head); //rec
    d(head);
    r2(head); //ite
    d(head);
}
