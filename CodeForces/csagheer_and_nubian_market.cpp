#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define lli long long int

int costs[111111];
int n;
int s;
map<string, pii> hc;

pii recursive(int sobc, int soi, int i, int noi)
{	


	int cost = sobc + soi*noi;
	if(i >= n || cost == s)
	{
		return make_pair(noi, cost);
	}

	ostringstream str1; 
	str1 << sobc << soi << i << noi;
	string key = str1.str();
	if(hc.find(key) != hc.end())
		return hc[key];
	// consider not buying the ith item
	pii ans1 = recursive(sobc, soi, i+1, noi);


	// consider buying the ith item
	int new_sobc = sobc + costs[i];
	int new_soi = soi + i + 1;
	int new_noi = noi + 1;

	int new_cost = new_sobc + new_soi * new_noi;

	if(new_cost <= s) // can buy this
	{
		pii  ans2 = recursive(new_sobc, new_soi, i+1, new_noi);
		if(ans1.first > ans2.first)
			hc[key]=ans1;
		else if(ans2.first > ans1.first)
			hc[key]=ans2;
		else{
			if(ans1.second < ans2.second)
				hc[key]=ans1;
			else
				hc[key]=ans2;
		}
	}
	else
		hc[key]=ans1;
	return hc[key];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n>>s;
	for(int i=0;i<n;i++)
		cin>>costs[i];
	pii ans = recursive(0, 0, 0, 0);
	cout<<ans.first<<" "<<ans.second;
}