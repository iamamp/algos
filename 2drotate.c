#include <stdio.h>
int a[6][6];
int b[6][6];

void main()
{
    int r1=4,c1=2; //lets contain our given rectangular 2d array inside a bigger square 2d array
    int i=0,j=0;

    printf("input matrix\n");
    for(i=0;i<r1;i++)
    {
        printf("\n");
        for(j=0;j<c1;j++)
        {
            a[i][j]=i*r1+j;
            printf("%5d",a[i][j]);          //just creating a random matrix and showing it
        }
    }
    printf("\n\nphysical rotation anticlockwise:\n\n");

    /*
    so for physical roatation
    http://stackoverflow.com/questions/42519/how-do-you-rotate-a-two-dimensional-array


    first a transpose is reqd
    a[i][j] is put in b[j][i]
    */
    for(i=0;i<r1;i++) for(j=0;j<c1;j++) b[c1-1-j][i]=a[i][j]; //transpose, reverse rows, 90 anticlock

    for(i=0;i<c1;i++)
    {
        printf("\n");
        for(j=0;j<r1;j++) printf("%5d",b[i][j]);
    }


//--------------------------------------------------------------------------------------------------------
    printf("\n\nphysical rotation clockwise:\n\n");
    for(i=0;i<r1;i++) for(j=0;j<c1;j++) b[j][r1-1-i]=a[i][j]; //transpose, reverse cols, 90 clock


    for(i=0;i<c1;i++)
    {
        printf("\n");
        for(j=0;j<r1;j++) printf("%5d",b[i][j]);
    }



//--------------------------------------------------------------------------------------------------------
    printf("\n\nlogical rotation anticlockwise:\n\n");

    //displaying matrix as rotated is on similar lines
    for(i=0;i<c1;i++)
    {
        printf("\n");
        for(j=0;j<r1;j++) printf("%5d",a[r1-1-j][i]); //transpose, reverse rows, 90 anticlock
    }
    printf("\n\n");


}
