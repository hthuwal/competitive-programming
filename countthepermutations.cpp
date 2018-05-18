#include <cstdio>
#define m 1000000009
#define lli long long int
lli dp[1111][1111];
int hc()
{
    dp[0][0]=1;
    for(int i=1;i<1111;i++)
    {
        dp[0][i]=1;
        dp[i][i]=1;
        dp[i][0]=0;
    }
    for(int i=1;i<1111;i++)
        for(int j=i+1;j<1111;j++)
            dp[i][j]=0;
    
    for(int i=0;i<1111;i++)
    {
        for(int j=i-1;j>0;j--)
        {
            dp[i][j]=(dp[i][j+1]+dp[i-j][j])%m;
        }
    }
}
int main()
{
    hc();
    int t,a,s;
    for(scanf("%d",&t);t--;)
    {
        scanf("%d %d",&a,&s);
        printf("%lld\n",dp[a][s]);
    }
}