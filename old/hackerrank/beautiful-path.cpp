#include<bits/stdc++.h>
using namespace std;

struct trip{
    int node;
    int dist;
    vector<bool> visited;
    trip(int n, int dis, vector<bool> vis)
    {
        node = n;
        dist = dis;
        visited = vis;
    }
};

class Graph{
    public:
        int num_nodes;
        vector<pair<int, int> > *adj;
    Graph(int v)
    {
        num_nodes = v;
        adj = new vector<pair<int, int> >[num_nodes];
    }
    ~Graph()
    {
        delete[] adj;
    }
    void add_edge(int a, int b, int e)
    {
        adj[a].push_back({b, e});
        adj[b].push_back({a, e});
    }

    void dfs(int s, int d, vector<int> &visited, int &ans)
    {
        cout<<"s: "<<s<<endl;
        if(s == d and visited[d] < ans)
        {
            ans = visited[d];
        }
        else
        {
            for(int i=0;i<adj[s].size();i++)
            {
                auto nbr = adj[s][i];
                int v = nbr.first;
                int w = nbr.second;
                if(visited[v] == INT_MAX)
                {
                    visited[v] = (visited[s] | w);
                    dfs(v, d, visited, ans);
                    visited[v] = INT_MAX;
                }
            }
        }
    }

    int dijsktra(int s, int d)
    {
        vector<int> dist(num_nodes, INT_MAX);
        priority_queue<pair<int, int> > heap;

        dist[s] = 0;
        heap.push({0, s});
        while(!heap.empty())
        {
            auto top = heap.top(); heap.pop();
            int w = top.first;
            int u = top.second;
            for(auto nbr: adj[u])
            {
                int v = nbr.first;
                if(dist[v] > (dist[u] | nbr.second))
                {
                    dist[v] = (dist[u] | nbr.second);
                    heap.push({-dist[v], v});
                }
            }
        }
        return dist[d] == INT_MAX? -1 : dist[d];
    }
};
int main()
{
    int n,m,a,b,w;
    cin>>n>>m;
    Graph g(n);
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>w;
        g.add_edge(--a, --b, w);
    }
    cin>>a>>b;
    a--; b--;

    cout<<g.dijsktra(b, a);
    /** 
     * cout<<g.dijsktra(--a, --b);
     * 
     * Dijsktra wouldn't work
     *
     * Replacing sum operations by bitwise OR
     *
     * Consider three nodes A, B, C
     *
     * Multiple edges can exist
     * 
     * A -- B : 1
     * A -- B : 2
     * B -- C : 2
     *
     * min(A, C): dijsktra will give 3, correct answer is 2.
     *
     * Sub propblem dependency not true for bitwise OR
     */
    
    // vector<int> dist(n, INT_MAX);
    // int ans = INT_MAX;
    // dist[a] = 0;
    // g.dfs(a, b, dist, ans);
    // if(ans == INT_MAX)
    //     cout<<"-1";
    // else
    //     cout<<ans;
}