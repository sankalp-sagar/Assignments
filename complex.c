#include<stdio.h>

struct complex
{
    int n;
    int i;
};

void addcomplex(struct complex c1, struct complex c2);

int main()
{
    struct complex c1;
    struct complex c2;

    printf("Enter first number natural part : ");
    scanf("%d",&c1.n);
    printf("\nEnter first number imaginary part : ");
    scanf("%d",&c1.i);
    printf("\nEnter second number natural part : ");
    scanf("%d",&c2.n);
    printf("\nEnter second number imaginary part : ");
    scanf("%d",&c2.i);

    printf("\n");

    addcomplex(c1,c2);



    return 0;

}

void addcomplex(struct complex c1, struct complex c2)
{
    int n,i;
    char sign='+';

    n = c1.n + c2.n;
    i = c1.i + c2.i;
    
    if(i<0)
    {
        sign = '-';
        i = i*(-1);
    }


    printf("Addition : %d%c%di",n,sign,i);

}