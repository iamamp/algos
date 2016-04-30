#include <stdio.h>

typedef struct pair{
    int p;
    int w;
}pair;

pair items[5];
pair sack[32];
pair aux[16];
int kays[5];
int x[5];

void main()
{
    int i,n,k,m,j,l; //k the num of pairs in sack[] array (not the num of items!!) , l is num of pairs is aux[]
    pair c,temp;
    int max=0,loc;

    printf("entern num of items\n");
    scanf("%d",&n);

    printf("enter capacity of sack\n");
    scanf("%d",&m);

    printf("\nenter profit followed by weight\n");
    for(i=0;i<n;i++) scanf("%d%d",&items[i].p,&items[i].w);

    printf("\nitems are\nprofit\tweight\n");
    for(i=0;i<n;i++) printf("%d\t%d\n",items[i].p,items[i].w);

    sack[0].p=0; sack[0].w=0;   //THE FIRST ITEM IN A SET THAT YOU WUD DENOTE ON PAPER IN CURLY BRACES!!
    k=1;    //k is for?    //i is for items

    for(i=0;i<n;i++) //this loop run 2^n        //l is for this aux array,whatever its being used for
    {
        kays[i]=k;
        l=0;
        for(j=0;j<k;j++) //generate aux for that 'i' : add item 'i' to every item in sack[] and store result in aux[] //EDIT i think i remember whats goin on...CURLY BRACES,SETS
        {
            if( sack[j].w + items[i].w <= m )  //sack[0].w was 0
            {
                aux[l].p=sack[j].p+items[i].p;
                aux[l].w=sack[j].w+items[i].w;
                l++;                            //this 'l' is absolutely necessary!!
            }
        }
        for(j=0;j<l;j++) sack[k+j]=aux[j]; //CONCAT contents of aux[] to sack[], p is for navigating thru aux
        k+=l;

        for(j=0;j<k;j++) printf("\n%d-%d\t",sack[j].p,sack[j].w);
        printf("\n\n");
    }
    printf("\n");
    for(i=0;i<n;i++) printf("%3d",kays[i]);
    printf("\n");

    for(i=0;i<k;i++)
    {
        if(sack[i].p>max)
        {
            c=sack[i];
            max=sack[i].p;
            loc=i;
        }
    }
    printf("\ncurrent is %d-%d\n",c.p,c.w);

    for(i=n-1;i>=0;i--)
    {
        temp.p = c.p - items[i].p ;
        temp.w = c.w - items[i].w ;

        for(j=0;j<min(kays[i],loc);j++)
        {
            if( sack[j].p==temp.p && sack[j].w==temp.w )
            {
                x[i]=1;
                c=temp;
                break;
            }
            else x[i]=0;
        }
    }
    for(i=0;i<n;i++) printf("%3d",x[i]);
}

int min(int a,int b)
{
    if(b>a) return a;
    else return b;
}

/*
wt  val
1   1
3   4
4   5
5   7

sack capacity 7

{(0,0)}                                             {(1,1)}                 after adding 1st item to (0,0)
{(0,0),(1,1)}                                       {(3,4),(4,5)}           after considering 1st and adding 2nd item to all elements
{(0,0),(1,1),(3,4),(4,5)}                           {(4,5),(5,6),(7,9)}     after considering 1st and 2nd items and adding 3rd item to all elements
{(0,0),(1,1),(3,4),(4,5),(5,6),(7,9)}               {(5,7)(6,8)}            after considering 1st 2nd and 3rd items and adding 4th item to all elements

{(0,0),(1,1),(3,4),(4,5),(5,6),(7,9),(5,7)(6,8)}                            final set
*/
