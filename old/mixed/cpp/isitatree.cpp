#include<iostream>
#include<list>

using namespace std;
class Graph
{
    int n;//no. of vertices
    list<int> *adj;
public:
    Graph(int x)
    {
        this->n=x;
        adj = new list<int>[n];
    }
    void addedge(int v,int w)
    {
        adj[v].push_back(w);
    }
    bool bfs(int s)
    {
        bool *visited = new bool[n];
        for(int i=0;i<n;i++)
        {
            visited[i]=false;
        }
        list<int> hcqueue;
        list<int>::iterator i;
        hcqueue.push_back(s);
        visited[s]=true;
        while(hcqueue.size()!=0)
        {
            s=hcqueue.front();
            hcqueue.pop_front();
            for(i=adj[s].begin();i!=adj[s].end();++i)
            {
                if(!visited[*i])
                {
                    hcqueue.push_back(*i);
                    visited[*i]=true;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
                return false;
        }
        return true;
    }
    bool isCyclicUtil(int v,bool visited[],bool *recStack)
    {
        if(visited[v] == false)
    {
        visited[v] = true;
        recStack[v] = true;

        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if( !visited[*i] && Graph::isCyclicUtil(*i, visited, recStack))
            {
                return true;
            }
            else if(recStack[*i])
            {
                return true;
            }
        }
    }
    recStack[v] = false;
    return false;
    }
    bool iscycle()
    {
    bool *visited = new bool[V+1];
    bool *recStack = new bool[V+1];
    for(int i = 1; i <= V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
    for(int i = 1; i <= V; i++)
    {
        if(isCyclicUtil(i, visited, recStack))
            return true;
    }
    return false;
    }
};
int main()
{
    int n,m,a,b;
    cin >>n>>m;
    Graph g(n);
    while(m--)
    {
        cin>>a>>b;
        g.addedge(a-1,b-1);
    }
    if(g.bfs(0)==true && g.iscycle()==false)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
