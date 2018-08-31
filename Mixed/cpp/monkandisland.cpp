/*input
2
3 2
1 2
2 3
4 4
1 2
2 3
3 4
4 2
*/
#include <bits/stdc++.h>
using namespace std;
class Graph{
private:
	int V;
	vector<int> *list;
public:
	Graph(int v)
	{
		V=v;
		list = new vector<int>[v];
	}
	void addedge(int a,int b)
	{
		list[a].push_back(b);
		list[b].push_back(a);
	}
	int bfs()
	{
		queue<int> q;
		vector<int> visited(V,-1);
		visited[0]=0;
		q.push(0);
		while(!q.empty())
		{
			int front = q.front();q.pop();
			for(int i=0;i<list[front].size();i++)
			{
				if(visited[list[front][i]]==-1)
				{
					visited[list[front][i]]=visited[front]+1;
					q.push(list[front][i]);
				}
			}
		}
		return visited[V-1];
	}
};
int main()
{
	int t,n,m,x,y;
	for(scanf("%d",&t);t--;)
	{
		scanf("%d %d",&n,&m);
		Graph g(n);
		for(int i=0;i<m;i++)
		{
			scanf("%d %d",&x,&y);
			g.addedge(--x,--y);
		}
		printf("%d\n",g.bfs());
	}
}