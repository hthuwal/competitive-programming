#include <bits/stdc++.h>
#define l(i,n) for(int i=0;i<n;i++)
using namespace std;

int t,n;
int adj[21][21];
long dp[2097152][21]; // pow(2, 21) = 2097152

int nsb(int n)
{
	int count = 0; 
    while (n) 
    { 
      n &= (n-1) ; 
      count++; 
    } 
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
						dp[sub][i] += dp[sub ^ (1<<j)][i-1];
				}
			}
		}
	}

	cout<<dp[0][n-1]<<"\n";
}

/**
* O(n* 2^n) algo
* More Complicated
*/
void solve2()
{
	int nps = pow(2, n);
	long dp[nps];
	memset(dp, 0, sizeof(dp));

	//dp[mask]
	//let number of set bits in mask=x
	//dp[mask] denote the number of ways of assigning the set of x items (denoted by mask) to
	//x people 0 to x-1
	for(int sub=0;sub<nps;sub++)
	{
		int niaa = nsb(sub); //number_of_items_already_assigned

		// try to assign a new item from the list of items
		for(int item=0;item<n;item++)
		{
			// only if the item hasn't already been assigned
			// and the xth item is willing to take this item
			if(!bit(item, sub) and adj[niaa][item]==1)
			{
				// if no item has already been assigned
				if(niaa == 0)
					dp[sub|1<<item] = 1;
				else
					dp[sub|1<<item] += dp[sub];
			}
		}
	}
	cout<<dp[nps-1]<<"\n";
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

		solve2();
	}
}