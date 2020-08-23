#include <cstdio>
#include <algorithm>
#include <climits>
#define lli long long int
using namespace std;

bool comp(lli a,lli b)
{
    return a>b;
}

int main()
{
    // freopen("in.txt","r",stdin);
    lli t,n,a[111111];
    for(scanf("%lld",&t);t--;){
        
        scanf("%lld",&n);
        
        for(lli i=0;i<n;i++)
            scanf("%lld",&a[i]);
        sort(a,a+n,comp);

        for(lli i=1;i<n;i++)
            a[i]=a[i]+a[i-1];
 
        lli max_uptill_now=LONG_LONG_MIN;
        lli current = 0;
        for(lli i=0;i<n;i++)
        {
            current = a[i]*(i+1)+a[n-1]-a[i];
            if(current>max_uptill_now)
                max_uptill_now=current;
            
        }
        printf("%lld\n",max_uptill_now);
    }
}