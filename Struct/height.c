#include<stdio.h>

struct height
{
    int feet;
    int inch;
};

int main()
{
    struct height h1 = {6,2};
    struct height h2 = {5,4};
    int sumf,sumi,difff,diffi;
    int carry=0;

    sumi = h1.inch + h2.inch;
    if(sumi>11)
    {
        sumi = sumi-12;
        carry = 1;
    }
    sumf = h1.feet + h2.feet + carry;
    carry = 0;
    printf("Sum : %d'%d",sumf,sumi);

    diffi = h1.inch - h2.inch;
    if(diffi<0)
    {
        diffi = 12 + diffi;
        carry = 1;
    }
    difff = h1.feet - h2.feet - carry;

    printf("\nDifference : %d'%d",difff,diffi);

    return 0;
}