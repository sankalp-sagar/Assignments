#include<stdio.h>

struct time
{
    int hrs;
    int min;
    int sec;
};

int main()
{
    struct time t1 = {10,20,50};
    struct time t2 = {5,30,40};
    int sumh,summ,sums,diffh,diffm,diffs;
    int carry = 0;

    sums = t1.sec + t2.sec;
    if(sums>60)
    {
        sums = sums - 60;
        carry = 1;
    }
    
    summ = t1.min + t2.min + carry;
    carry = 0;
    if(summ>60)
    {
        summ = summ - 60;
        carry = 1;
    }
    sumh = t1.hrs + t2.hrs + carry;

    carry = 0;

    diffs = t1.sec - t2.sec;
    if(diffs<0)
    {
        diffs = 60 + diffs;
        carry = 1;
    }
    diffm = t1.min - t2.min - carry;
    carry = 0;
    if(diffm<0)
    {
        diffm = 60 + diffm;
        carry = 1;
    }
    diffh = t1.hrs - t2.hrs - carry;

    printf("Sum : %d:%d:%d\nDifference : %d:%d:%d",sumh,summ,sums,diffh,diffm,diffs);

    return 0;
}