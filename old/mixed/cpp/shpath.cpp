#include <iostream>
#include <cstdio>
#include <climits>
#include <vector>
#include <set>
#include <utility>
#include <map>

#define INF INT_MAX

using namespace std;
class Graph{
	int V;//number of vertices
	vector < pair<int,int> > *adj; //adjacency list
public:
	Graph(int v);
	void addEdge(int u,int v,int w);
	int dijkstra(int src,int dest);
};

Graph::Graph(int v)
{
	V=v;
	adj = new vector<pair<int,int> >[V];//creating adjacency list;
}

void Graph::addEdge(int u,int v,int w)
{
	u--;
	v--;	
	adj[u].push_back(make_pair(v,w));
	// adj[v].push_back(make_pair(u,w));
}
int Graph::dijkstra(int src,int dest)
{
	src--;
	dest--;
	set< pair<int,int> > setds;//set to hold vertices being processed//
								// (current distance from source pair,vertex)
	vector<int> dist(V,INF);//VECTOR FOR DISTANCES all initialized to INF;

	setds.insert(make_pair(0,src));
	dist[src]=0;

	while(!setds.empty())
	{
		//first vertex in set is minimum vertex
		pair<int,int> temp = *(setds.begin());
		setds.erase(setds.begin());

		// vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)

        int u = temp.second;

        //if this vertex is the destination return it
        if(u==dest)
        	return temp.first;

        // 'i' is used to get all adjacent vertices of a vertex
        for(int i=0;i<adj[u].size();i++)
        {
        	// Get vertex label and weight of current adjacent
            // of u.
            int v = adj[u][i].first;
            int w = adj[u][i].second;

            //  If there is shorter path to v through u.
            if(dist[v]>dist[u]+w)
            {
            	/*  If distance of v is not INF then it must be in
                    our set, so removing it and inserting again
                    with updated less distance.
                    Note : We extract only those vertices from Set
                    for which distance is finalized. So for them,
                    we would never reach here.  */
                if(dist[v]!=INF)
                	setds.erase(setds.find(make_pair(dist[v],v)));

                //updating distance of v
                dist[v]=dist[u]+w;
                setds.insert(make_pair(dist[v],v));
            }
        }
	}
	return dist[dest];
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif

	int t,n,e,p,w;
	string name;

	scanf("%d",&t);
	while(t--)
	{
		map<string,int> names;
		scanf("%d",&n);
		Graph g(n);
		for(int i=1;i<=n;i++)
		{
			cin>>name;
			names[name]=i;
			scanf("%d",&e);
			for(int j=0;j<e;j++)
			{
				scanf("%d %d",&p,&w);
                g.addEdge(i,p,w);
			}
		}
		scanf("%d",&p);
		for(int i=0;i<p;i++)
		{
			string x,y;
			cin>>x>>y;
			cout<<g.dijkstra(names[x],names[y])<<endl;
		}
	}
}
