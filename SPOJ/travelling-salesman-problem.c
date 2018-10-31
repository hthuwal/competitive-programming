/**
 * Travelling Salesman Problem
 *
 * https://www.spoj.com/problems/PESADA04/
 */

#include<stdio.h>
#include<limits.h>
// using namespace std;
int adj[15][15];

int min(int a, int b)
{
	return a < b? a: b;
}

int bit(int n, int j)
{
	return (n >> j) & 1;
}

int nsb(int n)
{
	int count= 0;
	while(n>0)
	{
		n=(n&(n-1));
		count++;
	}
	return count;
}

int tsp(int n)
{
	int subsets = 1<<n; // 2^n subsets possible
	int dp[subsets+5][n+5];

	// similar to shortest hamiltonian walk with a condition 0th node must be present
	// dp[i][j] denotes shortest path starting from 0 and going through
	// all nodes with set bit in i and ending at node j;
	// for all possible subset
	for(int sub=0; sub<subsets; sub++)
	{
		for(int j=0;j<n;j++)
		{
			// if the subset doesn't contain the starting vertex no possible solution
			if(!bit(sub, 0)) 
				dp[sub][j] = INT_MAX;
			// else if it contains the starting vertex and has only 1 node in the set
			else if(nsb(sub) == 1)
				dp[sub][j] = 0;
			else
			{
				dp[sub][j] = INT_MAX; 
				for(int k=0;k<n;k++)
					if(k!=j && bit(sub, k) && dp[sub ^ (1<<j)][k] != INT_MAX)
						dp[sub][j] = min(dp[sub][j], dp[sub ^ (1<<j)][k] + adj[k][j]);
			}
		}
	}

	// ans is the min over all i (shortest hamiltoninan walk starting from 0 and ending at i + dist of 0 from i)
	int ans = INT_MAX;
	for(int i=1;i<n;i++)
	{
		if(dp[subsets-1][i] + adj[i][0] < ans)
			ans = dp[subsets-1][i] + adj[i][0];
	}
	return ans;
}

int main()
{
	int n, t;

	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);
		n++;
		// reading the adjacency matrix
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i==j)
					adj[i][j] = 0;
				else
					scanf("%d",&adj[i][j]);
			}
		}
		printf("%d\n", tsp(n));
	}
}