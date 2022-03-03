/**
 * https://www.hackerrank.com/challenges/find-the-nearest-clone/
 * 
 * In this challenge, there is a connected undirected graph where each of the nodes is a color. 
 * Given a color, find the shortest path connecting any two nodes of that color. 
 * Each edge has a weight of 1. If there is not a pair or if the color is not found, print -1.
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
	vi colors;
public:
	Graph(int v)
	{
		this->V = v;
		this->list = new vi[v];
		this->colors.resize(v, -1);
	}
	void addedge(int u, int v)
	{
		this->list[u].push_back(v);
		this->list[v].push_back(u);
	}
	void setcolor(int i, int c)
	{
		this->colors[i] = c;
	}
	int num_colors()
	{
		int num = 0;
		for(int i=0;i<colors.size();i++)
			if(colors[i] > num)
				num = colors[i];
		return num;
	}

	/**
	 * Runs BFS keeping track of distance from source node
	 * @param  s [source node]
	 * @return   [the distance of the first node of same color as the souce, INT_MAX if no such node exist]
	 */
	int bfs(int s)
	{
		vector<int> visited(V, -1);
		queue<int> q;
		q.push(s);
		int target_color = colors[s];
		visited[s]=0;
		while(!q.empty())
		{
			int u = q.front();
			q.pop();
			for(int i=0;i<list[u].size();i++)
			{
				int v = list[u][i];
				if(visited[v] == -1)
				{
					visited[v] = visited[u] + 1;
					q.push(v);
					if(colors[v] == target_color)
						return visited[v];
				}
			}
		}
		return INT_MAX;
	}

	/**
	 * Find the closest pair of nodes with color = target_color
	 * @param  target_color
	 * @return [the distance between the closest pair, -1 if no such pair exist]
	 */
	int nearest_pair(int target_color)
	{
		int ans = INT_MAX;
		for(int i=0; i<V; i++)
		{
			// for every node with color = target color
			if(colors[i] == target_color)
			{
				// find the closest node with the same color as target_color
				int temp = bfs(i);

				// if this is shortest yet, update ans
				if(temp < ans)
					ans = temp;

				// if this is 1, return 1. Because nothing can be shorter than a distance of 1
				if(temp == 1)
					return 1;
			}
		}
		if(ans == INT_MAX)
			return -1;
		else
			return ans;
	}
};


int main()
{
	int n, m, c, a, b, target_color;
	scanf("%d %d",&n, &m);
	Graph g(n);
	for(int i=0; i<m; i++)
	{
		scanf("%d %d", &a, &b);
		g.addedge(--a, --b);
	}
	for(int i=0; i<n;i++)
	{
		scanf("%d", &c);
		g.setcolor(i, c);
	}
	scanf("%d",&target_color);
	printf("%d\n", g.nearest_pair(target_color));
}