#include <stdio.h>

void main()
{
    int min[1000];
    int select[1000];
    int coin[100];
    int m;  //count of coins
    int n;  //required sum
    int i; //iterating thru coins
    int j; //iterating thru sums from 0 to n

    printf("enter required sum and num of coins\n");
    scanf("%d%d",&n,&m);

    printf("\nenter the coins\n");
    for(i=0;i<m;i++) scanf("%d",&coin[i]);

    printf("\nn(sum reqd) is %d\nm(coins) is %d\n",n,m);
    min[0]=0;

    for(j=0;j<=n;j++)
    {
        if(j==0) min[0]=0;
        else     min[j]=99;             //as infinity
        select[j]=-1;                   //-1 indicating this sum is imposs to form

        printf("%3d",min[j]);
    }

    printf("\n\ncoins are\n");
    for(i=0;i<m;i++) printf("%3d",coin[i]);

    printf("\n\n");

    //start
    for(i=0;i<m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(coin[i] > j) continue; //a 5 cent coin can never make a 3cent total
            else
            {
                if(min[j] > 1+min[j-coin[i]])
                {
                    min[j] = 1+min[j-coin[i]];  //keep as it is, or take this coin(so add 1)   and    add with coins required for(this total - val of this coin)
                    select[j] = i;              //the first coin ud select if you wanted this total
                }
            }
        }
    }

    for(j=0;j<=n;j++) printf("%3d",min[j]);
    printf("\n");
    for(j=0;j<=n;j++) printf("%3d",select[j]);
    printf("\n");
    for(j=0;j<=n;j++) printf("%3d",j);
}

/*
one of the easiest bottom up dp questions
what makes this solution awesome is that if your first coin is 3 say,
then for totals 0,1 and 2 it will be impossible, and for total 3 it will take one coin

so if all your other coins are bigger than 3, when you are calculating some greater values, and (some greater total)-(val of some greater coin) comes to 3,
you can make use of this min[3]=1

and for any coin with value n,
the solution automatically optimises min coins reqd for total 0 to total n-1(ie imposs with this coin).
and for total n itself, just use one copy of this coin
*/
