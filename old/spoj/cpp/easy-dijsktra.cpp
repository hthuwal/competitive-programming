#include<bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define vi vector<pi>
#define vvi vector<vi>
#define lli long long int

class Graph{
public:
	int v;
	vvi adj;
	Graph(int v)
	{
		this->v = v;
		adj.resize(v);
	}
	void addedge(int u, int v, int w)
	{
		adj[u].push_back({v, w});
	}
	lli dijsktra(int s, int d)
	{
		priority_queue<pi> heap;
		heap.push({0, s});

		vector<lli> dist(v, INT_MAX);
		dist[s] = 0;

		while(!heap.empty())
		{
			auto top = heap.top(); heap.pop();
			int u = top.second;

			for(auto nbr: adj[u])
			{
				int v = nbr.first;
				int w = nbr.second;

				if(dist[u] + w < dist[v])
				{
					dist[v] = dist[u] + w;
					heap.push({-dist[v], v});
				}
			}
		}
		return dist[d];
	}
};

int main()
{
	cin.sync_with_stdio(false);
	int t,v,k,w,a,b;
	cin>>t;
	while(t--)
	{
		cin>>v>>k;
		Graph g(v);
		for(int i=0;i<k;i++)
		{
			cin>>a>>b>>w;
			g.addedge(--a, --b, w);
			// g.addedge(b, a, w);
		}
		cin>>a>>b;
		auto dist = g.dijsktra(--a, --b);
		if(dist == INT_MAX)
			cout<<"NO"<<"\n";
		else
			cout<<dist<<"\n";
	}
}