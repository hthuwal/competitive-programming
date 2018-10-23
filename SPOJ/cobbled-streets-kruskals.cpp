/**
 * https://www.spoj.com/problems/CSTREET/
 *
 * MST using kruskals
 */

#include <bits/stdc++.h>
#define pii pair<int, int>
#define vpi vector<pii>
using namespace std;

struct edge{
	int u, v, e;
	bool operator<(const edge o)
	{
		return e < o.e;
	}
};

struct Graph{
	int num_nodes;
	vector<edge> edges;
	int *parent;
	int *size;
	Graph(int v)
	{
		num_nodes = v;
		parent = new int[v];
		size = new int[v];
		for(int i=0;i<v;i++)
		{
			size[i] = 1;
			parent[i] = i;
		}
	}

	~Graph()
	{
		delete[] parent;
		delete[] size;
	}

	void addedge(edge e)
	{
		edges.push_back(e);
	}

	int find(int a)
	{
		if(parent[a] == a)
			return a;
		return parent[a] = find(parent[a]);
	}

	void uni(int a, int b)
	{
		int pa = find(a);
		int pb = find(b);
		if(pa != pb)
		{
			if(size[pb] > size[pa])
				swap(pb, pa);

			parent[pb] = pa;
			size[pa] += size[pb];
		}
	}

	int mst_cost_kruskals()
	{
		int cost = 0;
		sort(begin(edges), end(edges));
		for(auto e: edges)
		{
			if(find(e.u) != find(e.v)) 
			{
				cost += e.e;
				uni(e.u, e.v);
			}
		}
		return cost;
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
			g.addedge({--a, --b, c});
		}
		printf("%d\n", g.mst_cost_kruskals()*p);
	}
}