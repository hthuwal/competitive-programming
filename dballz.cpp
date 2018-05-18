#include<bits/stdc++.h>
using namespace std;

int blast[1000];
int duration[1000];

int ans(int energy, int l)
{
	int dp[1000001] = {0};

	dp[0] = 0;
	for(int i=1; i<=energy; i++)
	{
		dp[i]=0;
		for(int j=0; j<l; j++)
		{
			int temp = 0;
			if(i >= blast[j])
				 temp = duration[j] + dp[i - blast[j]];
			if(temp > dp[i])
				dp[i] = temp;
		}
	}
	return dp[energy];
}

int main()
{
	freopen("in.txt", "r", stdin);
	int t, energy, l;

	for(scanf("%d", &t);t--;)
	{
		scanf("%d %d", &energy, &l);
		// cout<<l;
		for(int i=0; i<l; i++)
			scanf("%d", &blast[i]);
		for(int i=0; i<l; i++)
			scanf("%d", &duration[i]);

		printf("%d\n", ans(energy, l));
	}
}