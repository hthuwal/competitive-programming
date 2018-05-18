#include <cstdio>
#include <algorithm>
#define mod 1000000007
#define lli long long int
using namespace std;

void print(lli a[],lli n)
{
    for(int i=0;i<n;i++)
        printf("%lld ",a[i]);
    printf("\n");
}
int main()
{
    freopen("in.txt","r",stdin);
    lli t,p,q,r,x1,z1,ans,ysquare,xy,zy,xz;
    lli x[111111],y[111111],z[111111];
    lli xx[111111],zz[111111];
    scanf("%lld",&t);
    while(t--)
    {
        // prllif("%lld",t);
        scanf("%lld %lld %lld",&p,&q,&r);
        for(lli i=0;i<p;i++)
            scanf("%lld",&x[i]);
        for(lli i=0;i<q;i++)
            scanf("%lld",&y[i]);
        for(lli i=0;i<r;i++)
            scanf("%lld",&z[i]);

        sort(x,x+p); sort(y,y+q); sort(z,z+r);
        // print(x,p);print(y,q);print(z,r);
        
        xx[0]=x[0]%mod;
        for(lli i=1;i<p;i++)
            xx[i]=((xx[i-1]%mod)+(x[i]%mod))%mod;

        zz[0]=z[0]%mod;
        for(lli i=1;i<r;i++)
            zz[i]=((zz[i-1]%mod)+(z[i]%mod))%mod;
        
        // printf("cumulative\n");
        // print(xx,p);print(zz,r);

        ans = 0;
        for(lli i=0;i<q;i++)
        {
            x1 = (upper_bound(x,x+p,y[i])-x)-1;
            z1 = (upper_bound(z,z+r,y[i])-z)-1;

            if(x1>=0 && z1>=0)
            {
                ysquare = (((x1+1)%mod)*((z1+1)%mod))%mod;
                // printf("ysquare is: %lld\n",ysquare);
                ysquare = (ysquare * (((y[i]%mod) *(y[i]%mod))%mod))%mod;
                // printf("x1 : %lld \nz1 : %lld",x1,z1);
                // printf("ysquare is: %lld\n",ysquare);
                xy = ((xx[x1]%mod)*(y[i]%mod))%mod;
                xy = (xy%mod * (z1+1)%mod)%mod;
                // printf("xy is: %lld\n",xy);
                zy = ((zz[z1]%mod)*(y[i]%mod))%mod;
                zy = (zy%mod * (x1+1)%mod)%mod;
                // printf("zy is: %lld\n",zy);
                xz = ((xx[x1]%mod)*(zz[z1]%mod))%mod;
                // printf("xz is: %lld\n",xz);
                ans = (ans%mod + ysquare%mod)%mod;
                ans = (ans%mod + xy%mod)%mod;
                ans = (ans%mod + zy%mod)%mod;
                ans = (ans%mod + xz%mod)%mod;
                // printf("current ans is: %lld\n",ans);
            }
            // printf("after %lld iteration of y %lld\n",i,ans%mod);
        }
        printf("%lld\n",ans%mod);
    }
}
