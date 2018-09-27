#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

class Graph{
private:
	int V;
	vi *list;
public:
	Graph(int v)
	{
		this->V = v;
		list = new vi[V];
	}
	void addedge(int a, int b)
	{
		list[a].push_back(b);
	}
	int bfs(int s, int g)
	{
		queue<int> q;
		int visited[V] = {0};

		visited[s]=1;
		q.push(s);
		while(!q.empty())
		{
			int front = q.front();
			q.pop();
			for(int i=0;i<list[front].size(); i++)
			{
				int nbr = list[front][i];
				if(visited[nbr] == 0)
				{
					visited[nbr] = visited[front] + 1;
					if(nbr == g)
						return visited[nbr];
					q.push(nbr);
				}
			}
		}
		return visited[g];
	}
};
int main()
{
	int f,s,g,u,d;
	scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
	Graph hc = Graph(f);
	for(int i=0;i<f;i++)
	{
		if(i+u < f)
			hc.addedge(i, i+u);
		if(i-d >= 0)
			hc.addedge(i, i-d);
	}
	int ans = hc.bfs(--s, --g)-1;
	if(ans == -1)
		printf("use the stairs");
	else
		printf("%d", ans);
}