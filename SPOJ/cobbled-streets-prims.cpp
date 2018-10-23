/**
 * https://www.spoj.com/problems/CSTREET/
 *
 * MST using prims
 */

#include <bits/stdc++.h>
#define pii pair<int, int>
#define vpi vector<pii>
using namespace std;

struct Graph{
	vpi *adj;
	int num_nodes;
	Graph(int v)
	{
		num_nodes = v;
		adj = new vpi[v];
	}
	~Graph()
	{
		delete [] adj;
	}
	void addedge(int a, int b, int w)
	{
		adj[a].push_back({b, w});
		adj[b].push_back({a, w});
	}
	int mst_cost_prims()
	{
		// default behaviour is max_heap, we need min so push negative of actual values
		priority_queue<pii> heap; 
		heap.push({0, 0});
		vector<bool> visited(num_nodes, false);
		vector<int> dis(num_nodes, INT_MAX);

		dis[0] = 0;
		while(!heap.empty())
		{
			pii top = heap.top(); heap.pop();
			int u = top.second;

			if(!visited[u]) // handeled by the comparison condition in dijsktra
			{
				visited[u] = true;
				for(pii nbr: adj[u])
				{
					int v = nbr.first;
					int e = nbr.second;

					// vistied handeled by the comparison condition in dijsktra
					if(e < dis[v] and !visited[v])
					{
						dis[v] = e;
						heap.push({-dis[v], v}); // pushing negative because max heap
					}
				}
			}
		}
		int cst = 0;
		for(int i=0;i<num_nodes;i++)
			cst += dis[i];
		return cst;
	}
};

int main()
{
	int t, n, m, p, a, b, c;
	for(scanf("%d",&t);t--;)
	{
		scanf("%d %d %d",&p, &n, &m);
		Graph g(n);
		for(int i=0;i<m;i++)
		{
			scanf("%d %d %d",&a, &b, &c);
			g.addedge(--a, --b, c);
		}
		printf("%d\n", g.mst_cost_prims()*p);
	}
}