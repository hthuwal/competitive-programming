#include<cstdio>
#define x 1000007
using namespace std;
int main()
{
    long long int t,n,ans;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        ans=n;
        ans=ans*((3*n)+1);
        ans=ans/2;
        ans=ans%x;
        printf("%lld\n",ans);
    }
    return 0;
}
