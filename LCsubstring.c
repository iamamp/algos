#include <stdio.h>
int x[21][21]; //max length allowed for either string is 20

void main() //the principle used here is consecutive matching current characters in both strings. if a mismatch found anywhere,then all prev progress is lost!!
{
    char a[20],b[20];
    int la,lb,i,j,max;
    printf("enter string a and string b\n");
    gets(a);
    gets(b);
    la=strlen(a);
    lb=strlen(b);

    for(i=0;i<=la;i++) for(j=0;j<=lb;j++) x[i][j]=0;

    for(i=1;i<=la;i++) //a is horizontal,b is vertical
    {
        for(j=1;j<=lb;j++)
        {
            if (a[i-1]==b[j-1]) x[i][j]=x[i-1][j-1]+1;
            else x[i][j]=0;
        }
    }

    for(i=0;i<=la;i++)
    {
        printf("\n");
        for(j=0;j<=lb;j++) printf("%3d",x[i][j]);
    }
}

/*
similar to lc subsequence,
you are gnna have that m+1 X n+1 matrix

now approach is harsher in this question
first of all if no match is found give a straight zero.
yeah, this is gnna result in kinda a sparse matrix

so when you are moving forward horizontally in a row and you find a match look at top left element,take it and add one

THERE IS ONLY ONE FINITE ELEMENT IN EACH ROW!!!
*/
