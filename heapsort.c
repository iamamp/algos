#include <stdio.h>

void min_heapify(int* a,int i,int n) //i is considered as some parent(it may be childless tho)
{
    int j=2*i,temp; //2*i implies left child, where i is parent

    while(j<=n) //while at a left child (a leaf) which is still within the heap
    {
        if( j+1 <= n && a[j+1] < a[j] ) j+=1;   //make j the greater of the two children (if at all the right child exists)
        if(a[i] < a[j]) break;                  //min heap property well satisfied
        else                   //i is parent,j is greater child(or only child-(left))
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;

            i=j;                                    //i gat promoted to twice its val
            j*=2; //j gat even bigger!              //by default u are landing at the left child
                                                    //BASICALLY MOVING DOWN AS WE DO IN HEAP SORT, CHECKING TO SEE IF WE DISTURBED IT DOWN THERE
        }
    }
}

void delete_min(int* a,int n) //n is the num of elements
{
    int temp;
    temp=a[1];
    a[1]=a[n];
    a[n]=temp;
    min_heapify(a,1,n-1);
}

void main()
{
    int a[10]={-1,5,3,17,10,20,19,6,22,9}; //0th element doesnt matter
    //int a[10]={-1,0,99,99,99,99,99,99,99,99};
    int i,n=9;
    int m=n; //backup of the count

    for(i=n/2;i>=1;i--) min_heapify(a,i,n);//i stands for the parent. This creates a min heap from the input array
    //ALWAYS ALWAYS ALWAYS BEGIN FROM N/2       (WHY?? COZ ITS THE LAST PARENT. ITS THE ONE WHERE YOU START YOUR HEAPIFYING PROCESS)

    printf("\nthe heap is\n");
    for(i=1;i<n+1;i++) printf("\t%d",a[i]);

    while(m!=1)
    {
        delete_min(a,m);
        m--;
    }

    printf("\nafter sorting\n");
    for(i=1;i<n+1;i++) printf("\t%d",a[i]);
}

/*

plain english explanation:

so you have an input array, the elements in it should start from index 1 onwards (NOT index 0)
cause the input array itself is gnna be used as heap

AAAH!! so heres the most fundamental thing id forgotten abt heaps:
at any node (ASSUMING MIN HEAP),
it(data) is smaller than its children!

so next, your heapifying process starts from the


                                **********LAST PARENT************


in the array. and TRUST ME its at index n/2

so you make calls to min heapify exactly n/2 times  (going from n/2 to 1) from node n/2 to node 1 considering each as an individual parent
in each call you ensure that the acting parent in that call is smaller than either of its children
also if any swaps are made, DOWNWARDS HIERARCHY COULD BE DISTURBED

eg if you had:

                    40
                   / \
                  /   \
                 /     \
                20     10
               / \     /
             60  50   30

             in the call to node n=1 ie root node ie 40,

             a swap would give you:

                    10
                   / \
                  /   \
                 /     \
                20     40
               / \     /
             60  50   30

            which is disturbing the 40 30 pair
            so youve got to go downwards and fix it

THEN,
you start deleting root one by one in a delete_min function

the delete_min not only removes the root(putting last element in its place)
but also makes heap property corrections after the removal, same as shown in above diags

HOW? THE DELETE_MIN ITSELF CALLS MIN HEAPIFY AT THE ROOT!!!

the removed elements are put in answer array

THATS IT!


note that to make your code easier, in heapify fn just remember that dont let the function's actions begin if you dont even have a left child at current node!


SO BASICALLY AT EACH STAGE YOURE GNNA NEED THE HEAPIFY FUNCTION
*/



/*
TIME COMPLEXITY OBSERVATIONS:   YOU CAN JUST SKIP THIS PART!!!!

for a tree/heap with just one node,height of the tree is 0 ***

1) ***for a heapify function,the max no of swaps at any node at height h is also h

and

2) ***there are 2^(H-h) such nodes at a height h,

where H is height of tree itself

***So to build a heap from an array,H proportional to logn***

3) ***time taken = sigma h from 0 to H, (2^(H-h)       *         h)   (summation over)(nodes at a level * num of swaps of a node at that level)
                   sigma h from 0 to H 2^H/2^h         *         h
            2^H    sigma h from 0 to H 1/2^h         *         h


H is constant IN THIS EXPR. so u have 2^H sigma h from 0 to H, h/2^h
now for a bonus,take                  2^H sigma h from 0 to inf, h/2^h

by a certain defintion in corman bk,appendix a.8,  sigma h from 0 to inf, h/2^h  =  2
Almost done,now 2^H is n/2 and the sigma is 2,so u get n/2*2= n!!!***

THIS COULD PROBABLY BE WRONG. NO!!! OHHHHH SWEEEEET LORD !!! IM ACTUALLY RIGHT HERE!!!!!!!!!!!!!!!!!!!!!!!!!!

BUILDING A HEAP IS O(N)
HEAPSORT IS OLOGN
*/




/*
again, a VERY imp fact to be noted here,calling heapify MULTIPLE TIMES on an ENTIRE ARRAY to be converted to a heap is O(n)
***HOWEVER, calling heapify on only the root(AS IN THE CASE OF DELETE_MIN) is O(logN)!!!

9 months later, im finding this information USEFUL!!
*/





/*
now i cant find an expression for time complexity of heapsort itself..!
but i thought of how to derive something myself
consider a heap,
at height 3 : 1 node
at height 2 : 2 node
at height 1 : 4 node
at height 0 : 8 node

when u do heapsort,bottommost 8 nodes will need 3 swaps
4 nodes above that will need 2 swaps
2 nodes above that will need 1 swap
root node will need 0 swaps

so instead consider it as
8 nodes 3 swaps
4 nodes 3 swaps
2 nodes 3 swaps
1 node 3 swaps
so it means 15nodes*3swaps
n[logn]
*/
