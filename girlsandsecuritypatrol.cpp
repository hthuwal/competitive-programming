#include <cstdio>
#define lli long long int
int main()
{
    double u,v,x,t;
    for(scanf("%lf",&t);t--;)
    {
        scanf("%lf %lf %lf",&u,&v,&x);
        printf("%0.10lf\n",x/(u+v));
    }
}