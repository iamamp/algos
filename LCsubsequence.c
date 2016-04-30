#include <stdio.h>
int x[21][21];

void main()
{
    char a[20],b[20];
    int la,lb,i,j,max,p=0;
    printf("enter string a and string b\n");
    gets(a);
    gets(b);
    la=strlen(a);
    lb=strlen(b);
    char sequence[20];

    for(i=0;i<=la;i++) for(j=0;j<=lb;j++) x[i][j]=0;

    for(i=1;i<=la;i++) //a is vertical,b is horizontal,j moves faster,j moves left to right
    {
        for(j=1;j<=lb;j++)
        {
            if (a[i-1]==b[j-1]) x[i][j]=x[i-1][j-1]+1;
            else
            {
                if (x[i-1][j]>x[i][j-1]) x[i][j]=x[i-1][j]; //value at top
                else                     x[i][j]=x[i][j-1]; //value to left
            }
        }
    }

    for(i=0;i<=la;i++)
    {
        printf("\n");
        for(j=0;j<=lb;j++) printf("%3d",x[i][j]);
    }
    printf("\n");

    //now im thinking,max maynt be unique,but im thinking one of them Has to be at x[la][lb]
    i=la;
    j=lb;
    p=0;

    while(i>0 && j>0)
    {
        if(a[i-1]==b[j-1])
        {
            sequence[p++]=a[i-1];
            i--;
            j--;
        }

        else if(x[i][j]==x[i-1][j]) i--; //move one row up
        else j--; //move left by one col
    }
    sequence[p]='\0';
    strrev(sequence);
    puts(sequence);

}



/*

EDIT
plain english explanation 27 4 2016

abcdaf
acbcf

the longest common SUBSEQUENCE betn these two would be
abcf

that means you are to ignore some in between characters

now before you begin, if string a is m characters long and string b is n characters long,
you need a matrix of m+1 X n+1

with some zeros in it:

        a   b   c   d   a   f
    0   0   0   0   0   0   0
a   0   1   1   1   1   1   1
c   0   1   1  (2)  2   2   2
b   0   1  (2)  2   2   2   2
c   0   1   _2 (3)  3   3   3
f   0   1   2   3   3   3   4

so lets quickly fill up the values moving horizontally
there.

now here are the rules
at any place, if match is found, the value at top,topleft or left is gnna be the same, take that value and add 1 to it!
top left will make most sense mentally emotionally

look at the two parenthesised '2' there
the first one is from ac
the second one is from ab

now the second one from ab gave birth to the 3
so ab is the one we consider and ditch the ac!!



NOW IF MATCH IS NOT FOUND,
take from top or left WHICHEVER IS GREATER

WHY?

look at the _2
assume you dont know whats there...

to fill up this cell, you can either actually move from a-acbc to left which is ab-acbc...and copy the LEFT value

    OR

you can ***PRETEND*** to be at the top cell which is ab-acb and are moving downwards to ab-acbc...in which case you copy TOP value

so you choose the better of the two

its as simple as that

*/






