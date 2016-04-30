#include <stdio.h> //LIS roxx! take example as 1,5,7,8,2,3,4,5
//the new part is all about knowing how r is constructed. r basically contains indices that point element in a[] (as a predecessor)
//just keep in mind that at each moment you are finding the best candidate for last position in seq of *some length* plus 1**************************************

//all of the above comments aint makin no sense, so ima write a new fresh explanation below

int a[]={3,4,-1,5,8,2,3,12,7,9,10};
int n=11;
//int a[15];
//int n;
int t[15];  //note that this t array holds indices!!
int r[15]={-1};
int last=0; //note that 'last' also happens to be **********LENGTH********** of longest increasing subsequence seen so far minus one***

int i=0; //this guy is spl.

void ceil(int lo,int hi) //you are searching for an element immediately greater than a[i]
{
    int mid=(lo+hi)/2;

    if(lo==hi) //left with just one element
    {
        t[lo]=i;
        r[t[lo]]=t[lo-1]; //the element we just set is a successor to some element weve already visited!
        return;
    }
    if(a[i]<a[t[mid]])                         ceil(lo,mid); //why not mid-1? coz mid cud also be ur answer
    else /*if either a[i]>mid or a[i]==mid */ ceil(mid+1,hi); //mid is of no use,do mid+1
}

void main()
{
    int z[15];
    int x;
    /*
    printf("enter num\n");
    scanf("%d",&n);
    printf("enter elements\n");
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    */
    for(i=0;i<n;i++) { r[i]=-1; printf("%3d",r[i]); }
    printf("\n\n");

    t[0]=0; //index of last element of subseq of length "0" plus 1 is 0
    for(i=1;i<n;i++)
    {
        if( a[i] >= a[t[last]] )//simplest case, append to subsequence. u have found the largest element in the entire array yet.
        {
            last++;
            t[last]=i;
            r[t[last]]=t[last-1]; //r[i]=t[last-1]   //this element is a successor to the longest subsequence we ever saw before it!
        }
        else if( a[i] < a[t[0]] ) t[0]=i; //you have found the smallest element in the entire array yet
        else ceil(0,last);
    }
    printf("\n\n");
    for(i=0;i<n;i++) printf("%3d",a[i]);
    printf("\n\n");
    for(i=0;i<n;i++) printf("%3d",r[i]);
    printf("\n\n");
}

/*

so he has an input array

    3   4   -1  5   8   2   3   12  7   9   10

    0   1   2   3   4   5   6   7   8   9   10

now hes taken an 'r' array, init to -1
he also has a 't' array

and a length variable

now think of an array whose indices correspond to subsequences of size 'index'
what array 'r' stores is, is essentially the minimum possible last element of a subseq of size 'index'

ok to be fair its keeping the index of that min possible last element...

how is this array being constructed? a binary search is being used...!

lets look at thee build up of r array



0th element - coz theres no subsequence of size 0

1st element 0
coz index 0 points to 3
r is:
-   0
-   3
also 3 has no parent

next 4
-   0   1
-   3   4
coz 4 is greater than 3
and lis of size 2 are....only 3,4
of which 4 is the lowest last element
parent of 4 is 3

next -1
-1 is lesser than 3, so replace
so r is
-   2   1
-   -1  4
now -1,similar to 3 has no parent
but notice that parent of 4 is still 3!!!!

next 5
5 greater than 4 so append
r is:
-   2   1   3
-   -1  4   5
parent of 5 is 4

next 8
8 > 5 so append
r is:
-   2   1   3   4
-   -1  4   5   8
parent of 8 is 5

next 2
2 will replace 4
-   2   5   3   4
-   -1  2   5   8
parent of 2 is -1
but notice parent of 5 is still 4!

next 3
3 will replace 5
-   2   5   6   4
-   -1  2   3   8
parent of 3 is 2
but notice that parent of 8 is still 5!

next 12
12 is greater than 8, append
-   2   5   6   4   7
-   -1  2   3   8   12
parent of 12 is 8

next 7
7 will replace 8
-   2   5   6   8   7
-   -1  2   3   7   12
parent of 7 is 3
but parent of 12 is still 8!


next 9
9 will replace 12
-   2   5   6   8   9
-   -1  2   3   7   9
parent of 9 is 7

next 10
10 greater than 9, append
-   2   5   6   8   9   10
-   -1  2   3   7   9   10
parent of 10 is 9

10 9 7 3 2 -1
-1 2 3 7 9 10

E
p i C!!
*/
