#include <cstdio>
using namespace std;
int main()
{
    freopen("in.txt","r",stdin);
    int sum[2555],n,t,m,k,x,target;
    for(scanf("%d",&t);t--;)
    {
        scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&m);
            sum[i]=0;
            for(int j=0;j<m;j++)
            {
                scanf("%d",&x);
                sum[i]+=x;
            }
        }
        target = (k*(k+1))/2;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                
            }
        }
        for(int i=0;i<n;i++)
        printf("%d ",sum[i]);
    }
}