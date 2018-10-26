/**
 *  Graph is a tree. Therefore problem is to find the diameter
 *
 * 	Apply dijsktra from any node (a). Find the node farthest from (a) say (b)
 *
 *  Apply dijsktra from b. Find the node farthest from (b) say (c).
 *
 *  b and c are the farthest node
 *
 *  https://www.spoj.com/problems/BENEFACT/
 */
#include <bits/stdc++.h>
#define pi pair<int, int>
#define vi vector<pi>
using namespace std;

class Graph{
public:
	int n;
	vi *adj;
	Graph(int v)
	{
		n = v;
		adj = new vi[v];
	}
	~Graph()
	{
		delete[] adj;
	}
	void addedge(int a, int b, int c)
	{
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	pi dijsktra(int s)
	{
		priority_queue<pi> heap;
		vector<int> dis(n, INT_MAX);
		dis[s] = 0;
		heap.push({0, s});
		while(!heap.empty())
		{
			pi top = heap.top(); heap.pop();
			int u = top.second;
			for(int i=0;i<adj[u].size();i++)
			{
				int v = adj[u][i].first;
				int e = adj[u][i].second;
				if(dis[v] > dis[u] + e)
				{
					dis[v] = dis[u] + e;
					heap.push({-dis[v], v}); 
				}
			}
		}
		pi ans = {s, 0};
		for(int i=0;i<n;i++)
		{
			if(dis[i] != INT_MAX and dis[i] > ans.second)
			{
				ans.first = i;
				ans.second = dis[i];
			}
		}
		return ans;
	}
};
int main()
{
	int t,n,a,b,c;
	cin>>t;
	while(t--)
	{
		cin>>n;
		Graph g(n);
		for(int i=0;i<n-1;i++)
		{
			cin>>a>>b>>c;
			g.addedge(--a, --b, c);
		}
		pi k = g.dijsktra(0);
		cout<<(g.dijsktra(k.first).second)<<"\n";
	}
}