/**
 * https://www.hackerearth.com/challenges/competitive/march-circuits-19/algorithm/partitions-5fd40ffc/
 */

#include <bits/stdc++.h>
#define lli long long int
#define M 1000000007

using namespace std;

lli num_partitions(lli a[], lli n, lli lb, lli ub)
{
	lli dp[n+1] = {0};
	dp[n] = 1;

	for(int i=n-1;i>=0;i--)
	{
		// cout<<i<<"\n";
		lli sum = 0;
		for(int j=i;j<n;j++)
		{
			sum += a[j];
					
			if(sum > ub)
				break;

			if(sum >= lb)
				dp[i] = ((dp[i] % M) + (dp[j+1] % M)) % M;
		}
	}
	return dp[0];
}

int main()
{
	lli n, lb, ub;
	
	cin>>n>>lb>>ub;

	lli a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];

	cout<<num_partitions(a, n, lb, ub);
}