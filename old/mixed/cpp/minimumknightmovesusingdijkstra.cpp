#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
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
	int shpath(int i,int j,int p,int q);
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
int Graph::shpath(int i,int j,int p,int q)
{
	int src = i*8+j;
	int dest = p*8+q;

	set < pair<int,int> > setds;//distance frm source,label

	vector<int> dist(V,INT_MAX);
	
	dist[src]=0;
	setds.insert(make_pair(0,src));
	
	while(!setds.empty())
	{
		pair<int,int> current = *(setds.begin());
		setds.erase(setds.begin());
		int u = current.second;
		if(u==dest)
			return current.first;

		for(int i=0;i<adj[u].size();i++)
		{
			int v =  adj[u][i];
			if(dist[v]> dist[u]+1)
			{
				if(dist[v]!=INT_MAX)
					setds.erase(setds.find(make_pair(dist[v],v)));

				dist[v]=dist[u]+1;
				setds.insert(make_pair(dist[v],v));
			}
		}
	}
	return dist[dest];	
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
		cout<<g.shpath(i,j,p,q)<<"\n";
	}	
}