#include <stdio.h>
int f[100];

/*
value 0 1 1 2 3 5 8
index 1 2 3 4 5 6 7

NOTE THAT THERE IS NO F(0)! its defined from f(1) onwards
*/

int iterative(int n)
{
    if(n==1) return 0;
    if(n==2) return 1;
    int a=0,b=1,i,temp; //b is 1 step ahead of a

    for(i=2;i<n;i++)
    {
        temp=b; //store current value of b
        b+=a;   //take b to next level!
        a=temp; //take a to next level!! note b is still 1 step ahead of a!
    }
    return b;
}

int recursive(int n)
{
    if(n==1) return 0;
    if(n==2) return 1;
    return recursive(n-1)+recursive(n-2);
}

int recursive_m(int n)//start with f(3)  THIS IS CLEARLY o(n),just draw a recursion tree and check
{
    if(f[n]!=-1) return f[n]; //note that this is of no use for the outermost call
    return f[n]=recursive_m(n-1)+recursive_m(n-2);
}

void main()
{
    int n,i;
    for(i=0;i<101;i++) f[i]=-1;
    f[1]=0; //note!! f[0] is not suposed to be used! a mistake i was making earlier!
    f[2]=1;

    printf("enter n,the term that you want to be displayed\n");
    scanf("%d",&n);
    printf("%d\n",iterative(n));
    printf("%d\n",recursive(n));
    printf("%d\n",recursive_m(n));
}
