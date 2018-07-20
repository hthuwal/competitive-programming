#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

class Graph{
private:
	vi *list;
	int num_nodes;

public:
	Graph(int num_nodes){
		this->num_nodes = num_nodes;
		list = new vi[num_nodes];
	}	

	void addedge(int i, int j)
	{
		list[i].push_back(j);
		list[j].push_back(i);
	}

	vi bfs(int s)
	{
		vi visited(num_nodes,INT_MAX);
		
		queue<int> q;
		q.push(s);
		visited[s]=0;

		while(!q.empty())
		{
			int front = q.front();
			q.pop();

			for(int i=0; i<list[front].size(); i++)
			{
				if(visited[list[front][i]] == INT_MAX)
				{
					visited[list[front][i]] = visited[front] + 6;
					q.push(list[front][i]);
				}
			}
		}
		return visited;
	}
};

bool comp(pair<int, int> a, pair<int, int> b)
{
	return a.second < b.second;
}
int main()
{
	int t,n,m,u,v,s;
	for(scanf("%d",&t);t--;)
	{
		scanf("%d %d",&n,&m);
		Graph g = Graph(n);
		for(int i=0;i<m;i++)
		{
			scanf("%d %d",&u,&v);
			g.addedge(--u,--v);
		}
		scanf("%d",&s);
		vi ans = g.bfs(--s);

		for(int i=0; i<ans.size();i++)
		{
			if(i!=s)
			{
				if(ans[i] == INT_MAX)
					ans[i] = -1;
				printf("%d ", ans[i]);
			}
		}
		printf("\n");
	}
}