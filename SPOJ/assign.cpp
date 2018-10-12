#include <bits/stdc++.h>
#define l(i,n) for(int i=0;i<n;i++)
using namespace std;

int t,n;
int adj[21][21];
long dp[2097152][21]; // pow(2, 21) = 2097152

int nsb(int n)
{
	int count = 0;
	for(;n>0;n>>=1)
		if(n&1)
			count ++;
	return count;
}

int bit(int i, int n)
{
	return (n>>i) & 1;
}

/**
* O(n * n * 2^n) algo
* Gives TLE
*/
void solve()
{
	int nps = pow(2, n);
	
		// dp[i][j] denotes the number of ways assigniing topics to jth student
		// provided all the items corresponding to set bits of i have already been assigned
		
		// Has to be filled bottom up 
		// because the base case is when no topic is available to be assigned
		for(int sub=nps-1;sub>=0;sub--)
		{
			for(int i=0;i<n;i++)
			{
				dp[sub][i]=0;

				// if there is only one student and there is atleast one topic available
				if(i==0 and nsb(sub)<n)
				{
					// number of ways is basically the number of available topics that
					// the student likes
					for(int j=0;j<n;j++)
					{
						if(adj[i][j]==1 and bit(j, sub)==0)
							dp[sub][i] ++;
					}
				}
				// else i am the ith student and there are topics available
				else if(nsb(sub) < n)
				{
					// number of ways the topics can be assigned to remaining i-1
					// provided i took one of the available topics that i like
					for(int j=0;j<n;j++)
					{
						if(adj[i][j]==1 and bit(j, sub) == 0)
							dp[sub][i] += dp[sub ^(int)pow(2,j)][i-1];
					}
				}
			}
		}

		cout<<dp[0][n-1]<<"\n";
}

int main()
{
	
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--)
	{
		cin>>n;

		// Reading Input
		l(i,n) l(j,n) cin>>adj[i][j];

		solve();
	}
}