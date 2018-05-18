#include <cstdio>
#include <algorithm>
using namespace std;
#define N 1100000
#define lli long long int
lli a[N];

int main()
{
    freopen("in.txt","r",stdin);
    lli n,m;
    scanf("%lld %lld",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    sort(a,a+n);
    lli sum=a[n-1];
    lli x = 0;
    for(int i=n-2;i>=0;i--)
    {
        if(sum-a[i]*(n-1-i) >= m)
        {
            x = (sum-m)/(n-1-i);
            break;
        }
        sum = sum+a[i];
    }
    if(x==0) x = (sum-m)/(n);
    printf("%lld\n",x);
}