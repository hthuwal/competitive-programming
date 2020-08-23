#include<bits/stdc++.h>
using namespace std;

bool isset(int n, int i)
{
	return (n >> i) & 1;
}

int nsb(int n)
{
	int count = 0;
	while(n > 0)
	{
		n &= (n-1);
		count ++;
	}
	return count;
}

int first(int n)
{
	return log2(n&(-n));
}

int main()
{
	int n, m, a, b;

	scanf("%d %d",&n,&m);
	bool adj[n][n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			adj[i][j] = false;
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&a, &b);
		adj[--a][--b] = true;
		adj[b][a] = true;
	}


	int subsets = 1<<n;
	long long int dp[subsets][n];
	for(int sub=0; sub<subsets; sub++)
	{
		for(int j=0; j<n; j++)
		{
			dp[sub][j] = 0;
			if(nsb(sub) == 1 and isset(sub, j))
				dp[sub][j] = 1;
			else if(nsb(sub) > 1 and isset(sub, j))
			{
				for(int k=0;k<n;k++)
				{
					if(isset(sub, k) and first(sub) != j and adj[k][j] and dp[sub ^ (1<<j)][k])
						dp[sub][j] += dp[sub ^ (1<<j)][k];
				}
			}
		}
	}

	long long int ans = 0;
	for(int sub=0;sub<subsets; sub++)
	{
		for(int j=0;j<n;j++)
		{
			if(nsb(sub) >=3 and adj[first(sub),j])
				ans += (dp[sub][j]);
		}
	}
	ans = ans/2;
	printf("%lld\n", ans);
}