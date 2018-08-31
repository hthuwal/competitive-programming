#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
using namespace std;
class Graph{
private:
	int V;
	vector < int > *adj;
public:
	Graph(int V);
	void addEdge(int i,int j,int p,int q);
	int bfs(int i,int j,int p,int q);
};
Graph::Graph(int V)
{
	this->V=V;
	adj = new vector<int> [V];
}
void Graph::addEdge(int i,int j,int p,int q)
{
	int u = i*8+j;
	int v = p*8+q;
	adj[u].push_back(v);
}
int Graph::bfs(int i,int j,int p,int q)
{
	int u = i*8+j;
	int v = p*8+q;

	queue<pair<int,int> > hcq;

	vector<bool> visited(V,false);

	visited[u]=true;
	hcq.push(make_pair(u,0));
	while(!hcq.empty())
	{
		pair<int,int> temp = hcq.front();
		hcq.pop();

		if(temp.first==v)
			return temp.second;

		for(int i=0;i<adj[temp.first].size();i++)
		{
			if(!visited[adj[temp.first][i]])	
			{
				visited[adj[temp.first][i]]=true;
				hcq.push(make_pair(adj[temp.first][i],temp.second+1));
			}
		}
	}
}
void hc(Graph &g, int i,int j,int p,int q)
{
	if(p<8 && p>=0 && q>=0 && q<8)
		g.addEdge(i,j,p,q);
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	Graph g(64);
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			hc(g,i,j,i+1,j+2);
			hc(g,i,j,i+1,j-2);
			hc(g,i,j,i+2,j+1);
			hc(g,i,j,i+2,j-1);

			hc(g,i,j,i-1,j+2);
			hc(g,i,j,i-1,j-2);
			hc(g,i,j,i-2,j+1);
			hc(g,i,j,i-2,j-1);
		}
	}
	int t;
	cin>>t;
	while(t--)
	{
		string kt;
		cin>>kt;
		int i = kt[0]-'a';
		int j = kt[1]-'1';
		cin>>kt;
		int p = kt[0]-'a';
		int q = kt[1]-'1';
		cout<<g.bfs(i,j,p,q)<<"\n";
	}	
}