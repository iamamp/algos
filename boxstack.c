#include <stdio.h>

int k=0; //a global index for B[]
int in[4][3];
int B[20][3];

int max[20];
int parent[20]; //parent[2]=0 means 2 was placed on 0

void f(int r,int i) //taken from 'print all permutations of a string without reps'
{
    int j;
    int p;
    int x[10];
    for(j=0;j<10;j++) x[j]=1;

    if(i==2)
    {
        if(in[r][0]>in[r][1])
        {
            for(p=0;p<3;p++) B[k][p] = in[r][p];
            k++;
        }
        //printf("%3d%3d%3d\n",in[r][0],in[r][1],in[r][2]);
        return;
    }

    for(j=i;j<3;j++) //j is going from i to 3
    {
        if(x[j]) //ofc this has to be j NOT i!
        {
            swap(r,i,j);
            f(r,i+1);
            swap(r,i,j);
            x[j]=0;
        }
    }
}

void swap(int r,int i,int j)
{
    int temp = in[r][i];
    in[r][i]=in[r][j];
    in[r][j]=temp;
}

void swap_(int j)//swaps rows j,j+1
{
    int temp,p;
    for(p=0;p<3;p++)
    {
        temp=B[j][p];
        B[j][p]=B[j+1][p];
        B[j+1][p]=temp;
    }
}

void main()
{
    int n,i,j;
    printf("enter num of boxes\n");
    scanf("%d",&n);

    printf("enter the three dimensions for all boxes in any order\n");
    for(i=0;i<n;i++) scanf("%d%d%d", &in[i][0], &in[i][1], &in[i][2] );

    //now generate w l h combos. required condition is that l >= w in any combo,simplifying problem, no loss of gen
    for(i=0;i<n;i++) f(i,0);

    printf("\ntotal combinations : %d\n\n",k);
    for(i=0;i<k;i++) printf("%3d%3d%3d\n",B[i][0],B[i][1],B[i][2]);

    //now sort these combos in descending by base area
    for(i=0;i<k;i++) //there will be k rounds, in each round ith smallest element will take its place (towards right end)
        for(j=0;j<k-i-1;j++) if(B[j][0]*B[j][1] < B[j+1][0]*B[j+1][1]) swap_(j);

    printf("\nafter sorting by base area:\n\n");
    for(i=0;i<k;i++) printf("%3d%3d%3d\n",B[i][0],B[i][1],B[i][2]);

    //all working till now

    for(i=0;i<k;i++) max[i]=B[i][2];
    printf("\n\nmax array right now is\n");
    for(i=0;i<k;i++) printf("%3d",max[i]);

    for(i=1;i<k;i++) //i comes after j
    {
        for(j=0;j<i;j++)
        {
            if(B[j][0] > B[i][0] && B[j][1] > B[i][1])
            {
                max[i] = max[j] + B[i][2];
                parent[i] = j;
            }
        }
    }
    printf("\n\nmax array is\n");
    for(i=0;i<k;i++) printf("%3d",max[i]);
    printf("\n\nparent array is\n");
    for(i=0;i<k;i++) printf("%3d",parent[i]);
    printf("\n");

    //perfecT!!
}

/*
plain english explanation:
take boxes as input
5 3 2
4 2 1 say

generate combos of this input such that without loss of gen l always greater than w, h can be anything
ull get 3 of each box if each of l w and h are unique

5 3 2 a=15
5 2 3 a=10
3 2 5 a=6

4 2 1 a=8
4 1 2 a=4
2 1 4 a=2

after sorting by base a,

5 3 2
5 2 3
4 2 1
3 2 5
4 1 2
2 1 4

why? bcoz box with lesser base are atleast has a chance of going on a box with higher base area

then perform lis by height, appending if BOTH l and w are greater than prev
*/
