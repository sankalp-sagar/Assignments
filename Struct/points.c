#include<stdio.h>
#include<math.h>

struct point
{
    int x;
    int y;
};

int main()
{
    struct point p1 = {6,3};
    struct point p2 = {2,2};
    float d;

    d = sqrt(((p2.x-p1.x)*(p2.x-p1.x))+((p2.y-p1.y)*(p2.y-p1.y)));
    printf("Distance : %f",d);

    return 0;
}