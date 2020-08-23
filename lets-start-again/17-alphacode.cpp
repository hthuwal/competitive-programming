// https://www.spoj.com/problems/ACODE/

#include<bits/stdc++.h>
#define lli long long int
using namespace std;

lli dp[5111];

int main()
{
	string enc;
	while(true)
	{
		cin >> enc;
		if(enc == "0")
			break;

		int last = enc.length() - 1;

		dp[last+1] = 1;
		dp[last] = enc[last] == '0' ? 0 : 1;

		for(int i=last-1; i>=0; i--)
		{
			dp[i] = 0;
			if(enc[i] != '0')
				dp[i] = dp[i+1];
			
			bool cond1 = enc[i] == '1';
			bool cond2 = enc[i] == '2' && enc[i+1] <= '6';
			if(cond1 || cond2)
				dp[i] += dp[i+2];
		}
		cout<<dp[0]<<"\n";
	}
}