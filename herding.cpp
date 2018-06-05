#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

class Graph{
private:
	int V;
	int n,m;
	vi *list;

	int indices_to_node(int i, int j)
	{
		return i*m+j;
	}

public:
	Graph(int n, int m)
	{
		this->n = n;
		this->m = m;
		this->V = n*m;
		this->list = new vi[V];
	}
	void addedge(int i, int j, int k, int l)
	{
		int a = indices_to_node(i, j);
		int b = indices_to_node(k, l);
		list[a].push_back(b);
		list[b].push_back(a);
	}
	int num_connected_components()
	{
		bool visited[V] = {false};
		int ans = 0;
		for(int i=0; i<V; i++)
		{
			if(!visited[i])
			{
				ans++;
				bfs(i, visited);
			}
		}		
		return ans;
	}
	void bfs(int s, bool *visited)
	{
		queue<int> q;

		visited[s]=true;
		q.push(s);
		while(!q.empty())
		{
			int front = q.front();
			q.pop();
			for(int i=0; i<list[front].size(); i++)
			{
				int nbr = list[front][i];
				if(!visited[nbr])
				{
					visited[nbr] = true;
					q.push(nbr);
				}
			}
		}
	}
};


int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	Graph g = Graph(n, m);
	char row[m+2];
	for(int i=0;i<n;i++)
	{
		scanf("%s", row);
		for(int j=0;j<m;j++)
		{
			switch(row[j])
			{
				case 'S': g.addedge(i, j, i+1, j); break;
				case 'N': g.addedge(i, j, i-1, j); break;
				case 'W': g.addedge(i, j, i, j-1); break;
				case 'E': g.addedge(i, j, i, j+1); break;
			}
		}
	}
	printf("%d\n", g.num_connected_components());

}