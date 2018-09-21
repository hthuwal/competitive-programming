/**
 * https://www.hackerrank.com/challenges/torque-and-development/
 */

#include<bits/stdc++.h>
#define vi vector<int>
#define lli long long int
using namespace std;

/**
 * Graph Data structure
 */
class Graph{
private:
	int V;
	vi *list;
public:
	Graph(int v)
	{
		this->V = v;
		this->list = new vi[v];
	}
	void addedge(int u, int v)
	{
		this->list[u].push_back(v);
		this->list[v].push_back(u);
	}

	/**
	 * Perform dfs starting from s
	 * @param  s       [starting node]
	 * @param  visited [vector that keeps track of which nodes have been visited]
	 * @return         [the number of nodes in the component containing s]
	 */
	int dfs(int s, vector<bool> &visited)
	{
		int num_nodes = 0;
		stack<int> st;
		st.push(s);
		visited[s] = true;
		num_nodes ++;
		while(!st.empty())
		{
			int u = st.top();
			st.pop();
			for(int i=0;i<list[u].size();i++)
			{
				int v = list[u][i];
				if(!visited[v])
				{
					visited[v] = true;
					st.push(v);
					num_nodes ++;
				}
			}
		}
		return num_nodes;
	}

	/**
	 * Traverses the graph to find all the connected components
	 * @return [returns a list of number_of_nodes in each of the components]
	 */
	vi connected_components()
	{
		vi comp;
		vector<bool> visited(this->V, false);
		for(int i=0; i<this->V; i++)
		{
			if(!visited[i])
				comp.push_back(dfs(i, visited));
		}
		return comp;
	}
};

/**
 * Calculates the minimum cost of creating libraries/roads in graph.
 * @param  n  [Number of nodes in the graph]
 * @param  cl [Cost of creating library]
 * @param  cr [Cost of repairing road]
 * @return    the minimum cost
 *
 * Assumpition the graph with n node is connected.
 * Therefore we have a choice to break it into more components.
 * say we break it into k components. Then
 *
 * cost = k*(cl) + (n-k)*cr;  1 library per component and will have to repair (n-k) roads to keep each component connected.
 * cost = k*(cl-cr) + n*cr; k
 * cost = variable + constant;
 *
 * we need to minimize cost:
 * if cl >= cr => k*(cl-cr) is positive therefore we should keep k = 1(lowest possible) to minimize cost.
 * 		thus cost = 1*cl - 1*cr + n*cr = cl + (n-1)*cr
 * else if cl < cr => k*(cl-cr) is negative therefore we should keep k as high as possible i.e k = n to minimize ost
 * 		thus cost = n*cl - n*cr + n*cr = n*cl
 */
lli cost(lli n, lli cl, lli cr)
{
	if(cl>=cr)
		return cl+(n-1)*cr;
	else
		return n*cl;
}

int main()
{
	int q, n, m, cr, cl, a, b;
	for(scanf("%d",&q); q--; )
	{
		scanf("%d %d %d %d",&n, &m, &cl, &cr);
		Graph g(n);
		for(int i=0; i<m; i++)
		{
			scanf("%d %d", &a, &b);
			g.addedge(--a, --b);
		}
		vi comp = g.connected_components();
		lli total_cost = 0;
		
		for(int i=0; i<comp.size(); i++)
			total_cost += cost(comp[i], cl , cr);
		printf("%lld\n", total_cost);
	}
}