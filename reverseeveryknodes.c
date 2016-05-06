#include <stdio.h>
//ONE HELL OF A QUESTION

typedef struct node{
    char data;
    struct node* next;
}node;

node* head=NULL;
node* tail=NULL;

void add(int data)
{
    node* p;
    p=(node*)malloc(sizeof(node));
    p->data=data;
    p->next=NULL;

    if(!head)
    {
        head=p;
        tail=p;
    }
    else
    {
        tail->next = p;
        tail = p;
    }
}

void r(node* start,node* p,node* f) //reverses nodes between [start and f]. it can handle any case other than where p and f are same
                                    //if this fn was called, then at worst fnext will be NULL, as in end of list
{
    node* fnext = NULL;
    if(p==start) fnext = f->next;
    if(p->next != f) r(start,p->next,f);

    p->next->next=p;
    if(p==start) start->next=fnext;
}

void main()
{
    int i;
    int k=3; //the k of the problem statement,epic change this and see it work for all cases!
    int c=0;
    node* p;
    node* f=NULL;
    node* prev_p=NULL;

    for(i=0;i<8;i++) add(i+1);
    p=head;
    for(i=0;i<8;i++)
    {
        printf("%3d",p->data);
        p=p->next;
    }
    printf("\n\n");
    p=head;
    f=head;

    while(f)              //its natural to keep this loop running for only as long as f (or p, which is same) is valid
    {
        for(i=0;i<k-1;i++) if(f->next) f=f->next; //get f to last node of this iteration

        if (p==NULL) return;             //no element remaining
        else if(p==f)
        {
            prev_p->next = p;  //just one element remaining
            return;
        }
        else                            //two or more elements remaining
        {
            r(p,p,f);                   //after calling this fn, f and p will have interchanged their positions
            if(c==0) head = f;

            if(c!=0) prev_p->next = f;  //f is now at the start. connect the link before it to it(f)
            prev_p = p;             //('1'-2-3)-4-5-6 will become (3-2-'1')-4-5-6..,which will later become (3-2-'1')-6-5-4,so make a backup of p

            f = p->next;
            p = p->next;            //get p ready for next iteration
            c++;
        }
    }

    p=head;
    for(i=0;i<8;i++)
    {
        printf("%3d",p->data);
        p=p->next;
    }
}

/*
so this is how it works:
let given ll be
1 2 3 4 5 6 7 8

if k is 3,
expected output is
3 2 1 6 5 4 8 7

so first of all take your list in chunks of three:

in first iteration,
p=1
f=3
reverse this part recursively
so you have 3 2 1

connect the 1 to the 4 properly. you will need a backup of ptr to 4 before you start
so you have 3 2 1-4

NOW THE CATCH
4 5 6 will become 6 5 4 when its turn arrives.
so keep a backup ptr to 1 also, bcoz this 1-4 link will be broken and be reborn as a 1-6 link

repeat this as many times as you can. the recursive fn works for 2 or more elements from start to end, both inclusive

for just one element remaining, connect it and finish
for no element remaining, you got lucky, your work is done

*/
