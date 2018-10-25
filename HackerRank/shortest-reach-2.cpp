/**
 * https://www.hackerrank.com/challenges/dijkstrashortreach/problem
 */

#include <bits/stdc++.h>
#define pi pair<int, int>
#define vpi vector<pi>
using namespace std;

class Graph{
public:
	int n;
	vpi *adj;
	Graph(int v)
	{
		n = v;
		adj = new vpi[v];
	}
	void addedge(int a, int b, int w)
	{
		adj[a].push_back({b, w});
		adj[b].push_back({a, w});
	}

	/*
	Set: Number of pops: 3747, Time: 1m41.858s
	Heap: Number of pops: 3747, Time: 1m41.821ss

	Commented code: code for set
	 */
	vector<int> dijsktra(int s)
	{
		vector<int> dist(n, INT_MAX);
		
		priority_queue<pi> heap;
		heap.push({0, s});
		// set<pi> heap;
		// heap.insert({0, s});

		dist[s] = 0;
		
		int count = 0; //for benchmarking
		while(!heap.empty())
		{
			count++; //for benchmarking
			
			pi top = heap.top();  heap.pop();
			// pi top = *begin(heap); heap.erase(heap.begin());
			
			int u = top.second;

			for(auto nbr: adj[u])
			{
				int v = nbr.first;
				int w = nbr.second;
				if(dist[u] + w < dist[v])
				{
					dist[v] = dist[u] + w;
					heap.push({-dist[v], v});
					// heap.insert({dist[v], v});
				}
			}
		}
		printf("Number of pops: %d\n\n", count);
		return dist;
	}
};

int main()
{
	int t, n, m, a, b, c, s;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n, &m);
		Graph g(n);
		cout<<"Reading Edges\n";
		for(int i=0;i<m;i++)
		{
			scanf("%d %d %d",&a, &b, &c);
			g.addedge(--a, --b, c);
		}
		
		cout<<"dijsktra\n";
		scanf("%d", &s);
		vector<int> dist = g.dijsktra(--s);
		
		for(int i=0;i<n;i++)
		 	if(i!=s)
				printf("%d ", (dist[i] == INT_MAX? -1: dist[i]));
		printf("\n");
	}
}