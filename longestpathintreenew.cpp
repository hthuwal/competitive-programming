#include <bits/stdc++.h>
using namespace std;
class Graph{
private:
	long long int V;
	vector< long long int > *adj;
public:
	Graph(long long int V);
	void addEdge(long long int u,long long int v);
	pair<long long int,long long int> dfs(long long int src);
};
Graph::Graph(long long int V)
{
	this->V=V;
	adj = new vector<long long int> [V]; 
}
void Graph::addEdge(long long int u,long long int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
pair<long long int,long long int> Graph::dfs(long long int src)
{
	bool visited[V];
	for(long long int i=0;i<V;i++)
		visited[i]=false;

	stack< pair<long long int,long long int> > st;
	st.push(make_pair(src,0));
	long long int max=0;
	long long int v=0;

	while(!st.empty())
	{
		pair<long long int,long long int> top = st.top();
		st.pop();
		visited[top.first]=true;
		// cout<<top.first<<" "<<top.second<<"\n";
		if(top.second>=max)
		{
			max=top.second;
			v = top.first;	
		}
		// cout<<max1<<"#"<<max2<<"\n";
		for(long long int i=0;i<adj[top.first].size();i++)
		{
			if(!visited[adj[top.first][i]])
			{
				st.push(make_pair(adj[top.first][i],top.second+1));
			}
		}
	}
	return make_pair(v,max);
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	long long int n,u,v;
	cin>>n;
	Graph g(n);
	n--;
	while(n--)
	{
		cin>>u>>v;
		g.addEdge(--u,--v);
	}
	pair<long long int,long long int> temp = g.dfs(0);
	temp = g.dfs(temp.first);
	cout<<temp.second;
}