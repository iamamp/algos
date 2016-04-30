#include <stdio.h> //class question!!!
//spiral traversal of 2d array

void main()
{
    int a[10][10];
    int r=4;
    int c=6;
    int i=0,j=0,k=0;
    //int p=0,q=0;
    int T=0,B=r-1,L=0,R=c-1;
    int dir=0; //dir variable

    for(i=0;i<r;i++) for(j=0;j<c;j++) a[i][j]=k++;

    for(i=0;i<r;i++)
    {
        printf("\n");
        for(j=0;j<c;j++) printf("%5d",a[i][j]);
    }
    printf("\n\nthe solution\n\n");

    while(T<=B && L<=R && printf("\n"))
    {
        if(dir==0)
        {
            for(i=L;i<=R;i++) printf("%3d",a[T][i]);
            T++;    dir=1;
        }
        else if(dir==1)
        {
            for(i=T;i<=B;i++) printf("%3d",a[i][R]);
            R--;    dir=2;
        }
        else if(dir==2)
        {
            for(i=R;i>=L;i--) printf("%3d",a[B][i]);
            B--;    dir=3;
        }
        else if(dir==3)
        {
            for(i=B;i>=T;i--) printf("%3d",a[i][L]);
            L++;    dir=0;
        }
    }
}
