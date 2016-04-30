//algo to print a random node from a linked list, and you dont know the count of nodes
#include <stdio.h>

typedef struct node{
    int data;
    struct node* next;  //the struct in this line was necessary!!
}node;

node* head=NULL;

node* add(int data)
{
    node* temp=NULL;

    temp=(node*)malloc(sizeof(node));
    temp->data=data;
    temp->next=head;
    head=temp;
}

void print_random(node* head)
{
    int n=1;
    int data=head->data;
    node *current=head;

    if (!head) return;

    for(n=1;current!=NULL;n++)
    {
        if(rand()%n==0) data=current->data;
        current=current->next;
    }
    printf("\nrandom node: %d\n",data);
}

/*

so i guess this is how it works:

lets say you have just one node, data = 1
so as per line 31 and 34, '1' will show up

for 2 nodes,
1   2
rand could be either even or odd
so theres 50-50 chance for either of the two to be selected
so youd be either positioned at 1
or at 2

but no matter whether you 'select' one or two,your 'current' pointer is always at the last discovered node

for 3 nodes
1   2   3
'selected' could be 1 or 2
'current' is at 3
only if rand%3 == 0, 'selected' will also become 3

for 4 nodes
1   2   3   4
'selected' could be 1 or 2 or 3
'current' is at 4
only if rand%4 == 0, 'selected' will also become 4

AWSOME
*/

void main()
{
    node* p;
    srand(time(NULL));
    //printf("%d",rand()); //yes it prints a random no each time!!
    add(1);
    add(2);
    add(3);
    add(4);
    add(5);
    add(6);
    add(7);
    p=head;

    while (p)
    {
        printf("%3d",p->data);
        p=p->next;
    }//that was the whole list..
    print_random(head);
}
