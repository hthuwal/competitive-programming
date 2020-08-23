#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pi pair<lli, lli>

lli crawl(lli large, lli small)
{
	lli diff = large - small;
	return diff / 2 + diff % 2;
} 

lli dijsktra(lli a, lli b, lli c)
{
	priority_queue<pi> heap;
	heap.push({0, a});

	map<lli, lli> dist;
	dist[a] = 0;

	while(!heap.empty())
	{
		auto top = heap.top(); heap.pop();
		lli u = top.second;
		cout<<u<<"\n";
		char fuck; cin>>fuck;
		vector<pi> nbrs;
		if(a==b)
			return top.first;

		if(a>b)
			nbrs.push_back({b, crawl(a,b)});
		else
		{
			if(u-2 > 0 and u-2 >= b/c)
				nbrs.push_back({u-2, 1});

			if(u-1 > 0 and u-1 >= b/c)
				nbrs.push_back({a-1, 1});

			if(u*c > 0 and u*c < b*c)
				nbrs.push_back({u*c, 1});
		}

		for(auto nbr: nbrs)
		{
			lli v = nbr.first;
			lli w = nbr.second;
			if(dist.find(v) == dist.end())
				dist[v] = INT_MAX;

			if(dist[u] + w < dist[v])
			{
				dist[v] = dist[u] + w;
				heap.push({-dist[v], v});
			}
		}
	}
	return dist[b];
}

int solve_rec(int a, int b, int c)
{
	cout<<a<<" "<<b<<" "<<c<<"\n";
	char d;
	cin>>d;
	if(a<=0)
		return INT_MAX / 10;
	if(a==b)
		return 1;
	if(a>b)
		return crawl(a, b);
	else
	{
		int ans = solve_rec(a*c, b, c);
		if(a > b/c)
		{
			ans = min(ans, solve_rec(a-2, b, c));
			ans = min(ans, solve_rec(a-1, b, c));
		}
		return 1 + ans;
	}
}

int main()
{
	lli t,a,b,c;
	cin.sync_with_stdio(false);
	cin>>t;

	while(t--)
	{
		cin>>a>>b>>c;
		cout<<a<<" "<<b<<" "<<c<<"\n";
		cout<<dijsktra(a, b, c)<<"\n";
	}
}