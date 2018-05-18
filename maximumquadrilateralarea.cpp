#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int t;
    double a,b,c,d,s,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
        ans=(-a+b+c+d)*(a-b+c+d)*(a+b-c+d)*(a+b+c-d);
        ans=sqrt(ans);
        ans=ans/4;
        printf("%0.2lf\n",ans);
    }
    return 0;
}
