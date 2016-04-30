#include <stdio.h>
//ascending  //epic question
// 4 observations 6 cases

int a[]={11,12,13,14,15,1,2,3,4,5,6,7,8,9,10}; //no duplicates, 3 IS THE MID right now
int n=14;

/*
SOME IMPORTANT OBSERVATIONS:

1) When u partition at the middle, one of the halves HAS TO BE completely sorted (Notice that 4 to 10 above is sorted)

2) If there is a finite rotation,then the other half is guaranteed to be UNSORTED (11 to 2 above)

3) IT ALSO MEANS THAT FIRST ELEMENT IS NOW GREATER THAN LAST: SORT OF AN ANOMALY (11 > 10)*** THIS IS THE SINGLE MOST IMPORTANT ONE. IT FORMS THE BASIS OF CASE 4


                                    ****************

4) AND LASTLY THE ROTATION COUNT IS ALL ABOUT FINDING THE SMALLEST ELEMENT IN THE ARRAY!!***********

                                    ****************


Now, the CASES: consider any rotation of any small array

case 1: only one element. DONE
case 2: only two elements. DONE!



Now we can peacefully talk abt three or more elements!!!!!!!!!!!!!!!!!

case 3: mid is LESSER than mid+1 AND mid-1. This is Ob, return mid. scenario like  4,5,1,2,3

case 4: you already know that Observation 3 says that if there has been any rotation, FIRST ELEMENT IS GREATER THAN LAST
        So first of all, right at the start, if there HASNT BEEN ANY ROTATION, GET OUT!

        Also, you may land up on a sorted section, a[lo] < a[hi], RETURN lo IMMEDIATELY
        Howd you come in such a situation?
        say you started with  4,5,6,7,1,2,3
        future case, case 6 says ditch left half. so THEN you get 1,2,3


***note that case 3 and 4 are done first coz they are immediate return cases
   NOW WE HAVE TO REALLY THINK OF THROWING AWAY PARTS OF OUR ARRAY!!!!!!!!!!!!!!!! cause in the end this is a binary search!!


   ACTUALLY CASE 3 AND 4 SPEED UP THE PROCESS...WITHOUT THEM UD STILL ARRIVE AT AN ANSWER!


case 5: RIGHT HALF COMPLETELY SORTED
        mid lesser than hi (naturally also lesser than mid+1) but not lesser than mid-1

        scenario like   5,1,2,3,4
        THIS MEANS SECTION TO RIGHT IS COMPLETELY SORTED. DITCH THE RIGHT SECTION

case 6: LEFT HALF COMPLETELY SORTED
        scenario like   2,3,4,5,1....DITCH LEFT HALF

*/

int f(int lo,int hi) //rotation count
{
    int mid=(lo+hi)/2;

    if(lo==hi) return lo;                                                   //case 1
    else if(lo==mid)                                                        //case 2
    {
        if (lo<hi) return lo;
        else       return hi;
    }

    if( a[mid] < a[mid+1] && a[mid] < a[mid+n-1] ) return mid;              //case 3, a[mid] the smallest ever
    else if( a[lo] < a[hi] )                       return  lo;              //case 4

    else if(a[mid]<a[hi])                          return f(lo,mid-1);      //case 5 ditch right half
    else /* if ( a[lo] < a[mid] ) */               return f(mid+1,hi);      //case 6 ditch left half
}

int p(int lo,int hi,int key) //search
{
    if(lo>hi) return -1;
    int mid=(lo+hi)/2;
    if (a[mid]==key) return mid;
    else if(a[lo]>a[mid]) //the sorted array is between mid and hi
    {
        if(key>a[mid] && key<=a[hi]) return p(mid+1,hi,key);
        else                         return p(lo,mid-1,key);
    }
    else /*if(a[mid]>a[hi])*/ //the sorted array is between lo and mid
    {
        if(key>=a[lo] && key<a[mid]) return p(lo,mid-1,key);
        else                         return p(mid+1,hi,key);
    }
}

void main()
{
    printf("rotated %d times\n",f(0,14));
    printf("element found at index %d\n",p(0,14,13)); //for searching the element you want..
}


