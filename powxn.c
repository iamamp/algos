#include <Stdio.h>
//the division by 2 ensures logn ness

int pow(int x,int n){
    if (n==0)      return 1;
    else if (n%2 == 0)
    {
        int y = pow(x,n/2);
        return y*y;
    }
    else return x*pow(x,n-1);
}

int wop(int x,int n) //U ARE GOING FROM BOTTOM TO TOP!!!!
{                    //3pow6 is the best example to understand this
    int r=1;
    while(n>0)
    {
        if(n%2==0)
        {
            n/=2;
            x*=x;  //3pow6 becomes 9pow3
        }
        else
        {
            r*=x;
            n--;
        }
    }
    return r;
}//i liked this!!

void main(){
    printf("%d\n",pow(3,6));
    printf("%d",wop(3,6));
}

/*
elegant solution!

x pow n = x pow n/2  X  x pow n/2 if n is even
        = x X x pow n-1           if n is odd
        = 1                       if n is 0
*/
