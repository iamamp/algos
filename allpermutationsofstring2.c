#include <stdio.h>
#define max 10
char s[max];
int c=0;  //count

//DONT MEMORISE CODE!! NEVER MEMORISE CODE!!

void swap(int i,int j)
{
    char temp=s[i];
    s[i]=s[j];
    s[j]=temp;
}


void f(int i,int l)//j will go from i to l  // l is len of string  //i started as 0 on first call
{
    int x[256]; //NOT GLOBAL!
    int j=i,k=0;

    for(k=0;k<256;k++) x[k]=1;  //its like a flag, let me see what is the exact purpose //THESE FLAGS ARE DISTINCT FOR EACH CALL!!
    if(i==l-1) { printf("%s\n",s); c++; return; }

    for(j=i;j<l;j++)//j travels between i and l
    {
        if (x[s[j]]) //this condition actually saves u from a LOT of recursion! //swap happens between i and j but u r checkin flag only of j!! SHOULD REMM BY HEART that only j flag is being checked
                                                                                //THE FLAG IS IMPORTANT*****
                     //if all chars are distinct, the flags doesnt matter
                     // in the VERY FIRST set of calls to f, youll see a lot of self swapping. that will give you your very first ans...the string itself,
                     //and after that i will still be 0,but j will mov fwd to 1, and some real swaps will be seen
        {
            swap(i,j);
            f(i+1,l);
            swap(i,j); //the future calls on prev line may modify the string but u need it back in original condition to replace char at i***
            x[s[j]]=0;
        }
    }
}

void main()
{
    int l,i=0;

    gets(s);
    l=strlen(s);
    f(0,l);
    printf("\n\n%d\n",c);
}

/*
this is a good question and may need like 5-10 mins if youre seeing after many days

FIRST THE LOGIC
better way to visualise

for abc


right now: _     abc
a swap a
        |
        right now: a    bc
        b swap b
                right now: ab   c     ----      PRINT abc    //note the 'if' clause { if(i==l-1) print } we enter new call, we are at c, c is at l-1, we print and RETURN!
        b swap back b
        |
        right now: a    bc
        b swap c
                right now ac    b     ----      PRINT acb
        b swap back c                                       //now at level 2 call, as per loop, for(j=i;j<l;j++) i is 1 l is 3 and j is also 3, so loop ENDS
        |
        right now: ab   c

a swap back a                                    //SWAPPING BACK IS VERY IMPORTANT!!
|
|
right now: _    abc
a swap b
        |
        right now: b    ac
        a swap a
                right now: ba   c     ----      PRINT bac
        a swap back a
        |
        right now: b    ac
        a swap c
                right now: bc    a     ----      PRINT bca
        a swap back c
        |
        right now: ba   c

a swap back b
|
|
right now: _    abc
a swap c
        |
        right now: c    ab
        a swap a
                right now: ca   b       ----    PRINT cab
        a swap back a
        |
        right now: c    ab
        a swap b
                right now: cb   a       ----    PRINT cba
        a swap back b
        right now: ca   b

a swap back c
|
|
right now: _    abc
NOW,j goes beyond c, OUTER loop exit. YES TRUST ME IM CORRECT


------------------------------------------------------------------------------------------------------------------------------------

now, plain english algorithm:

i is ACTING as the start of string (in each call), l is the length of string
also l-1 is the last char of string


you have abc
an outer loop will swap a
     with a, (itself)
then with b,
then with c

ie j going from i to l-1


after it did the first step, swapping a with a
recursive call will be made considering only bc,   a kept aside
ie f(i+1,l)

again,once inside the call, j will move from i to l-1
ie you have bc
the loop will swap b with b
                and b with c

after b with b is done, level 3 call will be made, WHERE LOOP WILL NOT BE ENTERED
so you will have ab kept aside, just c is there, you will PRINT AND RETURN


------------------------------------------------------------------------------------------------------------------------------------


for aba

right now: aba
right now: _     aba
a swap a    ***flag[a] is set!!***
        |
        right now: aba
        right now: a    ba
        b swap b
                right now: aba
                right now: ab   a     ----      PRINT aba
        b swap back b
        |
        right now: aba
        right now: a    ba
        b swap a
                right now: aab
                right now aa    b     ----      PRINT aab
        b swap back a
        |
        right now: aba

a swap back a                                    //SWAPPING BACK IS VERY IMPORTANT!!
|
|
right now: aba
right now: _    aba
a swap b
        |
        right now: baa
        right now: b    aa
        a swap a    ***flag[a] is set!!***
                right now: baa
                right now: ba   a     ----      PRINT baa
        a swap back a
        |
        right now: baa
        right now: b    aa
        a swap a? NO!
        |
        right now: baa

a swap back b
|
|
right now: aba
right now: _    aba
a swap a? NO!


//finish later plz
//NOTE THAT IT IS COMMON SENSE THAT
    LOOP OUTSIDE
    RECURSIVE CALL INSIDE

*/
