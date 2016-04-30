#include <stdio.h>  //this works ONLY for WHOLE NOS!! 0 included!!

void main() //just keep all elements within 100 now!
{
    int a[20];                              //also,its better if you have elements starting from a min value around 1 or more...!
    int middle[120],last[20],i,n,max=0;     //and if they are close in value to each other..

    printf("enter num of elements\n");
    scanf("%d",&n);

    printf("\nenter the elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if (a[i]>max) max=a[i];             //we dont have a min variable as our middle array has to start from 0!
    }

    printf("\nyou entered\n");
    for(i=0;i<n;i++) printf("%d\t",a[i]);

    printf("\n\nmax is %d\n",max);
    for(i=0;i<=max;i++) middle[i]=0;        //its like we have elements from 0 to max,whose counts we are going to set..

    for(i=0;i<n;i++) middle[a[i]]++;

    printf("\nnumber\t");
    for(i=0;i<=max;i++) printf("%d\t",i);
    printf("\ncount \t");
    for(i=0;i<=max;i++) printf("%d\t",middle[i]);

    for(i=1;i<=max;i++) middle[i]+=middle[i-1]; //this is the cumulativ addn step

    printf("\n\nafter cumulative addn..\n\nnumber\t");
    for(i=0;i<=max;i++) printf("%d\t",i);
    printf("\ncount \t");
    for(i=0;i<=max;i++) printf("%d\t",middle[i]);


    for(i=0;i<n;i++)
    {
        last[middle[a[i]]]=a[i];    //value of first array is index of second array
        middle[a[i]]--;             //value at this index is again index for first array
    }//****

    printf("\n\nsorted array is\n");
    for(i=1;i<=n;i++) printf("%d\t",last[i]);//if u use decrement somewhere ur final array will also be able to start from 0!
}

/*

---------------------------------------------------------------------------------------------

plain english expl:

[0][1][2][3][4]
 7  1  5  2  2               these are 5 elements!

get the max element : 7

create array of size 7+1
so this array goes from a[0] to a[7], 8 elements

take the counts of input elements in this 8 element array     CALL THIS THE COUNT ARRAY!

[0][1][2][3][4][5][6][7]
 0  1  2  0  0  1  0  1

take their cumulative addition:
[0][1][2][3][4][5][6][7]
 0  1  3  3  3  4  0  5

NOW,make an array of size 6 --- THE RESULT ARRAY
yes THIS ONE IS ALSO OF SIZE 5 + 1

res[count[a[i]]=a[i]
count[a[i]]--;

a[0] is 7
count[7] is 5
in res[5] put 7!        and decrement count[7] to 4


a[1] is 1
       /
count[1] is 1
           /
  in res[1] put a[1]        and decrement count[1] to 0


a[2] is 5
count[5] is 4
in res[4], put 5         and decrement count[5] to 3


a[3] is 2
       /
count[2] is 3
           /
  in res[3] put 2           and decrement count[2] to 2


a[4] is also 2
            /
    count[2] is 2
               /
      in res[2] put a[4]    and decrement count[4] to 2

damn this mofo is easy to follow but hard to remember!!
---------------------------------------------------------------------------------------------

enter num of elements
5

enter the elements
7
1
5
2
2

you entered
7       1       5       2       2

max is 7

number  0       1       2       3       4       5       6       7
count   0       1       2       0       0       1       0       1

after cumulative addn..

number  0       1       2       3       4       5       6       7
count   0       1       3       3       3       4       4       5

sorted array is
1       2       2       5       7
Process returned 5 (0x5)   execution time : 4.347 s
Press any key to continue.

*/
