#include <cstdio>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    long long int t,n,b;
    for(scanf("%lld",&t);t--;)
    {
        scanf("%lld %lld",&n,&b);
        long long int ans=0,c1,c2;
        if(n<b) ans=0;
        else
        {
          if(n/2 >= b)
          {
            c1 = n-n/2;
            c1 += (n/2)%b;
            c1 = c1*((n/2)/b);

            c2 = (n/2)/b;
            c2++;
            c2 = (n-c2*b)*c2;
            ans = c1>c2?c1:c2;
          }
          else
          {
              ans=n-b;
          }
        }
        printf("%lld\n",ans);
    }
}