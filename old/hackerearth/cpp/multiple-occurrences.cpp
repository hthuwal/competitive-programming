/**
 * https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/multiple-occurence-97c00160/
 **/
#include<iostream>
#include<unordered_map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int t, n, x;
	cin>>t;
	while(t--) 
	{
		cin>>n;
		unordered_map<int, pair<int, int>> freq; 
		for(int i=0; i<n; i++) 
		{
			cin >> x;
			if (freq.find(x) == freq.end()) {
				freq[x] = {i, i};
			} else {
				freq[x].second = i;
			}
		}

		int ans = 0;
		for(auto item: freq) {
			ans += item.second.second - item.second.first;
		}
		cout<<ans<<"\n";
	}
}