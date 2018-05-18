#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <climits>
#define MOD 1000000007
using namespace std;

class Graph{
	
	private:
		int V;
		vector<int> *adj;
		vector<int> knowledge;
		int dfsutility(bool visited[],int src);
	public:
		Graph(int v);
		~Graph();
		void addEdge(int u,int v);
		void addknowledge(int u,int k);
		vector<int> dfs();

};

Graph::Graph(int v)
{
	this->V=v;
	adj = new vector<int> [V];
	knowledge.reserve(V);
}

Graph::~Graph()
{
	delete[] adj;
}
void Graph::addEdge(int u,int v)
{
	// cout<<u<<" "<<v<<endl;
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void Graph::addknowledge(int u,int k)
{
	knowledge[u]=k;
}
vector<int> Graph::dfs()
{
	bool visited[V];
	vector<int> countofmaxofgrps;
	for(int i=0;i<V;i++)
		visited[i]=false;

	for(int i=0;i<V;i++)
	{
		if(!visited[i])
		{
			// cout<<i<<endl;//to display starting points of disconnected components of graph
			int max = dfsutility(visited,i);
			countofmaxofgrps.push_back(max);
		}
	}
	return countofmaxofgrps;
}
int Graph::dfsutility(bool visited[],int src)
{
	stack<int> st;
	int max=INT_MIN;
	int count=0;

	st.push(src);
	while(!st.empty())
	{
		int top = st.top();
		st.pop();

		if(!visited[top])
		{
			visited[top]=true;

			if(knowledge[top]>max)
			{
				count=1;
				max=knowledge[top];
			}
			else if(knowledge[top]==max)
			{
				count++;
			}

			for(int i=0;i<adj[top].size();i++)
			{
				if(!visited[adj[top][i]])
				{
					st.push(adj[top][i]);
				}
			}
		}
	}
	return count;
}
int main()
{
	/**
	 * reading input from file if not online_judge
	 */
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int v,x,e,y;
	cin>>v>>e;
	Graph g(v);
	for(int i=0;i<v;i++)
	{
		cin>>x;
		g.addknowledge(i,x);
	}
	for(int i=0;i<e;i++)
	{
		cin>>x>>y;
		x--;y--;
		g.addEdge(x,y);
	}
	vector<int> countofmaxofgrps = g.dfs();
	long long int ans=1;
	for(int i=0;i<countofmaxofgrps.size();i++)
	{
		ans = ((ans%MOD)*(countofmaxofgrps[i]%MOD))%MOD;
	}
	cout<<ans<<"\n";
}