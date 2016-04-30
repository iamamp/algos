/*
the logic is basically this
if given number IS indeed a palindrome, say 61316

then logic is:
    60000
+    1000
+     300
+      16
+       6

should be the same number as take 61316
with last 6*10000
second last 1*1000
third last 3*100
fourth last 1*10
and fifth last 6*1

now what we are gnna do ensures that when we take last 6,it will get multiplied by 10, 5 times
and when we take the second last 4

So,

take the last 6
multiply 0 by 10 and add 6 = 6

take second last 1
multiply 6 by 10 and add 1 = 61

take third last 3
multiply 61 by 10 and add 3 = 613

take fourth last 1
multiply 613 by 10 and add 1 = 6131

take fifth last 6
mutiply 6131 by 10 and add 6 = 61316

there you go

*/

#include <stdio.h>

int main()
{
    int input,n,rev=0;
    scanf("%d",&input);

    n=input;
    while(n>0)
    {
        rev = rev*10 + n%10;
        n/=10;
    }

    if (rev==input) printf("yo");
    else            printf("no");

    return 0;
}
