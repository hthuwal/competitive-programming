/**
 * https://www.hackerrank.com/challenges/the-quickest-way-up
 */

#include <bits/stdc++.h>

#define pi pair<int, int>
#define mp(a,b) make_pair(a, b)
#define vpi vector<pi>
#define vi vector<int>

using namespace std;

/**
 * Represent board as a graph and do bfs 
 * snakes and ladders have edge weight 0 rest have edge_weight 0

 */
class Board{
private:
	int V;
	vpi *list;
public:
	Board()
	{
		V = 100;
		list = new vpi[100];
		for(int i=0;i<100;i++)
		{
			int j = i+1;
			while(j<=99 && j-i<=6)
			{
				addedge(i, j, 1);
				j++;
			}
		}
	}
	void addedge(int a, int b, int e)
	{
		list[a].push_back(mp(b,e));
	}
	void clear_edges_of(int a)
	{
		list[a].clear();
	}
	int bfs(int s)
	{
		vector<int> visited(100, -1);
		queue<int> q;
		visited[s] = 0;
		q.push(s);

		while(!q.empty())
		{
			int u = q.front();
			q.pop();

			for(int i=0;i<list[u].size(); i++)
			{
				pi v = list[u][i];
				if(visited[v.first] == -1)
				{
					visited[v.first] = visited[u] + v.second;
					q.push(v.first);
				}
			}
		}
		return visited[99];
	}
};

int main()
{
	int t,l,s,a,b;
	for(scanf("%d",&t);t--;)
	{
		Board board;
		scanf("%d",&l);
		for(int i=0;i<l;i++)
		{
			scanf("%d %d",&a,&b);
			a--;b--;
			board.clear_edges_of(a);
			board.addedge(a, b, 0);
		}

		scanf("%d",&s);
		for(int i=0;i<s;i++)
		{
			scanf("%d %d",&a,&b);
			a--;b--;
			board.clear_edges_of(a);
			board.addedge(a, b, 0);
		}
		printf("%d\n", board.bfs(0));
	}
}