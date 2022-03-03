#include <cstdio>
#define lli long long int
lli c[1100];
lli eval(lli x,lli n)
{
    lli ans=c[0];
    for(int i=0;i<n;i++)
        ans=ans*x+c[i+1];
    return ans;
}
int main()
{
    freopen("in.txt","r",stdin);
    lli count=0,x,n,k;
    while(1)
    {
        scanf("%lld",&n);
        if(n==-1)
            break;
        count++;
        for(int i=0;i<n+1;i++)
            scanf("%lld",&c[i]);
        scanf("%lld",&k);
        printf("Case %lld:\n",count);
        for(int i=0;i<k;i++)
        {
            scanf("%lld",&x);
            printf("%lld\n",eval(x,n));
        }
    }
}