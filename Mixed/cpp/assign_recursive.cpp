/*Time Complextiy O(n^n)**/
#include <cstdio>
#include <vector>
using namespace std;

long long int hc(long long int a[25][25],long long int x,long long int n,char hash[25])
{
    if(x>n)
        return 1;
    else
    {
        long long int ans=0;
        for(long long int i=1;i<=n;i++)
        {
            if(hash[i]=='0' && a[x][i]==1)
            {
                hash[i]='1';
                ans+=hc(a,x+1,n,hash);
                hash[i]='0';
            }
        }
        return ans;
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    long long int a[25][25],c,n;
    for(scanf("%lld",&c);c--;)
    {
        char hash[25]="000000000000000000000000";
        scanf("%lld",&n);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%lld",&a[i][j]);
        
        printf("%lld\n",hc(a,1,n,hash));
    }
}