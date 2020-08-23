#include <bits/stdc++.h>
using namespace std;
#define vi vector<long>
map<long, vi> hc;

int main()
{
	long n, r, x;
	scanf("%ld %ld",&n,&r);

	// Maintain a hash table of key:num, value: list of indices where num occurs
	for(long i=0; i<n;i++)
	{
		scanf("%ld",&x);
		if(hc.find(x) == hc.end())
			hc[x] = vi(1,i);
		else
			hc[x].push_back(i);
	}

	long ans=0;

	// consider each key as the first element of the gp triplet
	for(auto it=hc.begin(); it!=hc.end();it++) 
	{
		long a = it->first;
		// check if 2nd and 3rd element of gp are present
		if (hc.find(a*r) != hc.end() and hc.find(a*r*r) != hc.end())
		{
			auto ith = it->second; // sorted list of indices of a
			auto jth = hc.find(a*r)->second; // sorted list of indces of a*r
			auto kth = hc.find(a*r*r)->second; // sorted list of indices of a*r*r

			for(long j=0; j<jth.size(); j++)
			{
				long mid = jth[j];
				auto h = upper_bound(kth.begin(), kth.end(), mid);

				if(h != kth.end())
				{
					auto l = lower_bound(ith.begin(), ith.end(), mid);
					
					// kitne indices of a*r*r, a*r ke index ke baad aate hain?
					long g = kth.end()-h;

					// kitne indices of a a*r se pehle aate hain
					long s = l-ith.begin();
					
					ans += (g*s);
				}

			}

		}
	}
	printf("%lld", ans);
}