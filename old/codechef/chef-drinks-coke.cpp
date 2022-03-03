/**
 * https://www.codechef.com/COOK109B/problems/COKE
 */

#include<bits/stdc++.h>

#define vi vector<int>

using namespace std;

int t,l,m,n,k,r,temp,price;

bool isfeasible(int temp){

	if(temp > k)
		temp = max(k, temp-m);
	else
		temp = min(k, temp+m);

	return temp>=l and temp <=r;			
}

int main()
{
	cin.sync_with_stdio(false);
	cin>>t;
	while(t--)
	{
		int ans = INT_MAX;

		cin>>n>>m>>k>>l>>r;
		
		for(int i=0;i<n;i++)
		{
			cin>>temp>>price;
			if(isfeasible(temp))
				ans = min(ans, price);
		}

		cout<<(ans == INT_MAX ? -1 : ans)<<"\n";
	}
}