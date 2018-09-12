/*
https://practice.geeksforgeeks.org/problems/most-frequent-word-in-an-array-of-strings/0
 */

#include <bits/stdc++.h>
using namespace std;
#define psi pair<string, int>

bool comp(psi a, psi b)
{
	if(a.second > b.second)
		return true;
	else if(a.second == b.second)
		return a.first < b.first;
	else
		return false;

}
int main()
{
	ios_base::sync_with_stdio(false);
	int t,n;
	for(cin>>t;t--;)
	{
		map<string, int> hash;
		string str;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>str;
			if (hash.find(str) == hash.end())
				hash[str] = 0;
			hash[str]++;
		}
		vector<psi> hc(hash.begin(), hash.end());
		sort(hc.begin(), hc.end(), comp);
		cout<<hc[0].first<<endl;
	}
}