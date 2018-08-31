#include <bits/stdc++.h>

#define INF INT_MAX
using namespace std;

class Graph{
	int V; //number of vertices

	vector< pair<int,int> > *adj;//storing vertex and weight pair for every edge
public:
	Graph(int V);
	void addEdge(int u,int v,int w);
	void shortestPath(int s);
};

Graph::Graph(int V)
{
	this->V=V;//setting vertex
	adj = new vector< pair<int,int> >[V];//creating adjacency list
}

void Graph::addEdge(int u,int v,int w)
{
	adj[u].push_back(make_pair(v,w));
	adj[v].push_back(make_pair(u,w));
}

void Graph::shortestPath(int src){
	set< pair<int,int> > setds;//set to hold vertices being processed//
                                //(current distance from source pair,vertex)

	vector<int> dist(V,INF);//VECTOR FOR DISTANCES all initialized to INF;

	setds.insert(make_pair(0,src));//insert source in set and initialize its destance as 0
    dist[src]=0;
	while(!setds.empty())
	{
		//first vertex in set is minimum vertex
		pair<int,int> temp = *(setds.begin());
		setds.erase(setds.begin());//remove this vertex(its minimum distance is finalized) 
                                    //its minimum and update its neighbours

		// vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)

        int u = temp.second;

        // 'i' is used to get all adjacent vertices of a vertex
        for(int i=0;i<adj[u].size();i++)
        {
        	// Get vertex label and weight of current adjacent
            // of u.
        	int v = adj[u][i].first;
        	int w = adj[u][i].second;

        	//  If there is shorter path to v through u.
        	if(dist[v] > dist[u]+w)
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

	printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}
int main()
{
	 // create the graph given in above fugure
    int V = 9;
    Graph g(V);

    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.shortestPath(0);

    return 0;
}
