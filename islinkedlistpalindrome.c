#include <stdio.h>

typedef struct node{
    int data;
    struct node* next;
}node;
node* head=NULL;
node* slow=NULL;

int ispal(node* head)//the function is 30 something lines but is extremely straightfwd
{
    /* node* */slow=head; //its global for reversing purposes
    node *fast=head;
    node *prev_of_slow=NULL;    //this one is for both breaking AND reconstruction purposes! required in both cases
    node *mid=NULL; //for odd nodes sll
    int res=1;

    if(head && head->next)//bcoz for 1 or lesser nodes,pointless exercise
    {
        while(fast && fast->next)
        {
            fast=fast->next->next; //if even nodes,then fast will point to head of 2nd half,if odd,fast will point to mid node
            prev_of_slow=slow;
            slow=slow->next;
        }
        if(fast)//if fast is NOT NULL there were ODD num of nodes,else even num of nodes. believe me if nextptr of last node is considered,picturing this will NEVER be a problem!
        {
            mid=slow;
            slow=slow->next;
        }
        prev_of_slow->next=NULL;
        r(slow);
        res=c(head,slow); //write a compare fun

        r(slow);//straighten the second half back to normal
        if(mid)
        {
            prev_of_slow->next=mid;
            mid->next=slow;
        }
        else prev_of_slow->next=slow;
    }
}

void r(node *p)
{
    if(!p->next)
    {
        slow=p;
        return;
    }
    r(p->next);
    p->next->next=p;    //this is the line which i FORGOT!!
    p->next=NULL;
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
}
/*

as said on gfg..:
move till the middle of the node using a fast and a slow
NOW THERELL BE TWO CASES<ONE OF EVEN NODES, OTHER OF ODD NODES
just add appropriate IF clauses when advancing your fast and slow pointers
(this part should be done on the go!)

so when you are at head of second half, reverse it.

and then make a comparison again
*/
