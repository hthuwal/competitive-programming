#include <cstdio>
#include <cmath>
int main()
{
    int t;
    double n,m,k;
    for(scanf("%d",&t);t--;)
    {
        scanf("%lf %lf %lf",&n,&k,&m);
        if(m<n)
            printf("0\n");
        else{
            printf("%d\n",(int)(log(m/n) / log(k)));
        }
    }
}