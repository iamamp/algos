#include <stdio.h>
#include <stdlib.h>
int a[6][6];

int maxfrom3(int a,int b,int c)
{
    if(a>b && a>c) return a;
    else if(b>a && b>c) return b;
    else return c;
}

void main()
{
    int n=6,i,j;
    time_t t;
    srand((unsigned) time(&t));

    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<n;j++)
        {
            a[i][j]=rand()%10;
            printf("%3d",a[i][j]);
        }
    }

    for(i=n-1;i>0;i--)
    {
        for(j=0;j<n;j++)
        {
                 if(j==0)   a[i-1][j]+=maxfrom3(0,a[i][j],a[i][j+1]);
            else if(j==n-1) a[i-1][j]+=maxfrom3(a[i][j-1],a[i][j],0);
            else            a[i-1][j]+=maxfrom3(a[i][j-1],a[i][j],a[i][j+1]);
        }
    }
    printf("\n\n");
    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<n;j++) printf("%3d",a[i][j]);
    }
}


