#include <cstdio>
#define N 111111
#define f(i,k,n) for(int i=k;i<n;i++)
int cubes[50]; //49^3 > N

int dp[N];

void cube()
{
    f(i,0,50) cubes[i]=i*i*i;
}

void dyn()
{
    int x;
    dp[0]=0;
    f(i,1,N)
    {
        dp[i]=N;
        f(j,1,50)
        {
            x = j*j*j;
            if(x > i)
                break;
            if(1+dp[i-x] < dp[i])
                dp[i]=1+dp[i-x];
        }
    }
}
int main()
{
    cube();
    dyn();
    int x,c;
    c = 1;
    while(scanf("%d",&x)!=EOF)
    {
        printf("Case #%d: %d\n",c,dp[x]);
        c++;
    }

}