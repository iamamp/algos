#include <stdio.h> //note that the algo on pg 348 itself encourages the use of globals!!
#define max 8

//remember that overwriting is taken care of by having a 1d array!

int n,x[max]; //a cell is represented as (x[k], k)

int check(int c,int i) //cell (i,c) vs cell(x[j],j)
{
    int j;

    for(j=0;j<c;j++) if(x[j]==i ||                  // ith row was where queen was placed....iterating thru x[] will check for row wise clash with row i
                        abs(x[j]-i)==abs(j-c))      //diagonal clash check....its checking by comparing row distance == col distance
                            return 0;
    return 1;
}

void display()
{
    int board[max][max];
    int i,j;

    for (i=0;i<n;i++) for(j=0;j<n;j++) board[i][j]=0;
    for (i=0;i<n;i++) board[x[i]][i]=1;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++) printf("%3d",board[i][j]);
        printf("\n");
    }
    printf("\n\n");
}

void f(int k)
{
    int i; //i is for trying various rows

    for(i=0;i<n;i++) //this is the kth column. check all rows 'i' in this kth column
    {
        if(check(k,i))
        {
            x[k]=i;
            if (k==n-1) display();
            else f(k+1); //make a call to next columns IFF more columns remain
        }
    }
}

void main()
{
    scanf("%d",&n);
    f(0);
}
