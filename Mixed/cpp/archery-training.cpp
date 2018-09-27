#include <cstdio>
#include <cmath>
#define PI 4.0*atan(1)

double ans(double x,double y, double r)
{

    double theta = PI - acos(r/sqrt(x*x+y*y)) + atan(y/x);
    double alpha = PI + acos(r/sqrt(x*x+y*y)) + atan(y/x);
    double x1 = x + r*cos(theta);
    double x2 = x + r*cos(alpha);
    if(x1<x2)
    {
        x = x1;
        y = y + r*sin(theta);
    }
    else{
        x = x2;
        y = y + r*sin(alpha);
    }
    printf("%0.6lf %0.6lf\n",x,y);
    
}

int main()
{
    int t,x,y,r;
    for(scanf("%d",&t);t--;)
    {
        scanf("%d %d %d",&x,&y,&r);
        ans(x,y,r);
    }
}