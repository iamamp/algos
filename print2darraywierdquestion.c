/*
given input matrix
0 1
3 4
6 7

print it this way:
0 , 3 , 6
0 , 3 , 7
0 , 4 , 6
0 , 4 , 7
1 , 3 , 6
1 , 3 , 7
1 , 4 , 6
1 , 4 , 7
*/

#include <stdio.h>

int a[10][10],r,c;
int x[10];  //x[i] will be col number at row i !

void main()
{
    int i,j;
    printf("enter num of rows and cols\n");
    scanf("%d%d",&r,&c);
    for(i=0;i<r;i++) for(j=0;j<c;j++) a[i][j]=(i*r)+j;

    for(i=0;i<r;i++)
    {
        printf("\n");
        for(j=0;j<c;j++) printf("%3d",a[i][j]);  //just init a simple 2d array
    }
    printf("\n\n");
    f(0);

}

/*
ok, this question is tricky bcoz you kinda need variable num of loopS
which i cant do

so

first of all you need a row loop outside....traversing a row
for every element selected in a row go deep down and do the same thing(select an element and go deep down)
if you cant go any further down, (ie at the last row) print that one selected element from each row.
use an array for this
*/

void f(int i)//i is row number!
{
    int k,t;
    for(k=0;k<c;k++)
    {
        x[i]=k;
        if (i==r-1)
        {
            printf("\n");
            for(t=0;t<r;t++)
            {
                printf("%d ",a[t][x[t]]);
                if(t!=r-1) printf(", ");
            }
        }
        else f(i+1);
    }
}
