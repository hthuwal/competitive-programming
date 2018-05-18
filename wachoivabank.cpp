#include <cstdio>
int dp[1001][201];
int p[51];
int w[51];

int pre(int k, int m)
{
	for(int i=0; i<=m; i++)
	{	
		dp[0][i] = 0;
		dp[i][0] = 0;
	}

	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dp[i][j] = dp[i][j-1];
			if(w[j-1] <= i)
			{
				int a = p[j-1]+dp[i-w[j-1]][j-1] ;
				dp[i][j] = dp[i][j]>a?dp[i][j]:a;
			}
		}
	}
	return dp[k][m];
}

int main()
{
	int t,k,m;
	for(scanf("%d",&t);t--;)
	{
		scanf("%d %d",&k,&m);
		for(int i=0;i<m;i++)
		{
			scanf("%d %d",&w[i],&p[i]);
		}
		printf("Hey stupid robber, you can get %d.\n",pre(k,m));
	}
}