#include <stdio.h>

int a[] ={0};

void main()
{
    a[6]=1;
    a[9]=1;
    a[20]=1;
    int x;
    scanf("%d",&x);
    printf("%d",f(x));
}

int f(int n)
{
    if(n<6)     return 0;
    if(n==6 || n==9 || n==20) return 1;
    //else
                return a[n]=f(n-6) || f(n-9) || f(n-20);
}

/*
dividing n pens into packs of 6 9 and 20
return 1 if no remainder
*/
