#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pi pair<int,int>
#define vvi vector<vector<pi>>

class Graph{
public:
	vvi adj;
	vi gas;
	int num_nodes;
	Graph(int v)
	{
		num_nodes = v;
		adj.resize(v);
		gas.resize(v);
	}	
	void add_edge(int u, int v, int c)
	{
		adj[u].push_back({v, gas[u] - c});
		adj[v].push_back({u, gas[v] - c});
	}
	pi bfs(int s, bool flag)
	{
		queue<int> q;
		vector<int> dist(num_nodes, INT_MAX);
		dist[s] = 0;
		q.push(s);

		while(!q.empty())
		{
			int u = q.front(); q.pop();
			for(auto nbr: adj[u])
			{
				int v = nbr.first;
				int gain = nbr.second;
				if(dist[v] == INT_MAX)
				{
					dist[v] = dist[u] + gain;
					q.push(v);
				}
			}
		}

		int high = -1;
		int dis = INT_MIN;

		for(int i=0;i<num_nodes;i++)
		{
			int cand = dist[i];
			if(flag)
				cand += gas[i];
			if(dist[i] != INT_MAX and cand > dis)
			{
				high = i;
				dis= cand;
			}
		}
		return {high, dis};
	}
};
;
int main()
{
	int n,u,v,w;
	cin>>n;
	Graph g(n);
	for(int i=0;i<n;i++)
		cin>>g.gas[i];

	for(int i=0;i<n-1;i++)
	{
		cin>>u>>v>>w;
		g.add_edge(--u, --v, w);
	}

	pi x = g.bfs(0, false);
	cout<<x.first<<" "<<x.second<<endl;
	x = g.bfs(x.first, true);
	cout<<x.first<<" "<<x.second<<endl;
	cout<<x.second;
}