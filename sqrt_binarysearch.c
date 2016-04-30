#include <stdio.h>
//both float and double by default are showing 6 digits after decimal point!!

void main()
{
    float d,precision=0.0001,start=0,end,mid;
    scanf("%f",&d);

    if(d==0 || d==1) { printf("%f",d); return; }

    if (d>1) end=d;
    else     end=1;
                                //at the BEGINNING OF ANY ITERATION theres just start and theres end, THERES NO MID...!!!
    while(end-start>precision)
    {
        mid=(start+end)/2;
        if(mid*mid==d) { printf("%f",mid); return; } //rare case
        else if(mid*mid<d) start=mid;
        else if(mid*mid>d) end=mid;
    }

    printf("start:%f\nend:%f\navg:%f\nactual:%f\n",start,end,(start+end)/2,sqrt(d)); return;
}
