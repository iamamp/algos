//find all subsets of size k of an array

#include <cstdio>  //EXCELLENT EXCELLENT QN!!
int a[]={1,2,3,4,5},b[5];
int size_a=5,size_b=3;

void g(int current_b,int current_a) //i is for navigating thru s[] from current to size
{
    for(int i=current_a;i<size_a;i++) //the i=current part takes care that elements in s[] before s[current] are not allowed for use again
    {
        b[current_b]=a[i]; //this means a[i] has been used up!!
        if(current_b==size_b-1)
        {
            for(int i=0;i<size_b;i++) printf("%d ",b[i]);
            printf("\n");
        }
        else g(current_b+1,i+1); //why i? bcz it may happen that 1,2,3  1,2,4  1,2,5 are over,so u are in series 1,3,X but [current_a] STILL points to 2, so you may end up allowing 1,3,3 which is clearly rong
    }
}

main()
{
    g(0,0); //the hint here is that u r only moving in ONE DIRECTION,to the right.
}
