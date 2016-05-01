#include <stdio.h> //spiral traversal recursive

int a[10][10];

void main()
{

    int r=4; //if theres 4 rows, it means last row is row 3
    int c=6;    // 6 cols means last col is col 5
    int i=0,j=0,k=0;
    int p=0,q=0;

    for(i=0;i<r;i++) for(j=0;j<c;j++) a[i][j]=k++;

    for(i=0;i<r;i++)
    {
        printf("\n");
        for(j=0;j<c;j++) printf("%5d",a[i][j]);
    }
    printf("\n\nthe solution\n\n");
    i=0;
    j=0;

    x(0,0,r-1,c-1);
}

void x(int r1,int c1,int r2,int c2) //r1c1 and r2c2 represent diagonally opposite ends of current subsection of given matrix
{
    if(r1>r2 || c1>c2) return;
    int i;

    for(i=c1;i<=c2;i++) printf("%5d",a[r1][i]);
    printf("\n");

    for(i=r1+1;i<=r2;i++) printf("%5d",a[i][c2]);
    printf("\n");

    for(i=c2-1;i>=c1;i--) printf("%5d",a[r2][i]);
    printf("\n");

    for(i=r2-1;i>=r1+1;i--) printf("%5d",a[i][c1]);
    printf("\n");

    x(r1+1,c1+1,r2-1,c2-1);
}

/*
solution is simple...strip the matrix by one row at top and bottom
    and by one col at left and right sides every time you go down by one level
*/
