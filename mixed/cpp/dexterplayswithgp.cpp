#include <cstdio>
#define lli long long int
int main()
{
    freopen("in.txt","r",stdin);
    lli t,r,s,p;
    for(scanf("%lld",&t);t--;)
    {
        scanf("%lld %lld %lld",&r,&s,&p);
        s=(s*(r-1))%p;
        s=(s+1)%p;
        lli ans=-1;
        lli pre=1;
        for(lli i=1;i<p&&s!=0;i++)
        {    
            pre = (pre*r)%p;
            if(pre==s)
            {
                ans=i;
                break;
            }
        }       
        printf("%lld\n",ans);
    }
}