#include<iostream>
#include<list>
#include<map>
using namespace std;
map<int,int>hc;
class graph
{
    int v;//number of vertices
    list<int> *adj;
    public:
        graph(int x)
        {
            this->v=x;
            adj = new list<int>[v+1];
        }
        void addedge(int x,int y)
        {
            adj[x].push_back(y);//pushing y into the adjacency list of x
            adj[y].push_back(x);
        }
        void bfs(int x)
        {
            bool *visited = new bool[v+1];
            hc[x]=0;
            list<int>q;
            for(int i=1;i<=v;i++)
            {
                visited[i]=false;
            }

            visited[x]=true;
            q.push_back(x);
            list<int>::iterator i;
            while(!q.empty())
            {
                x = q.front();
                q.pop_front();

                for(i=adj[x].begin();i!=adj[x].end();i++)
                {
                    if(!visited[*i])
                    {
                        visited[*i]=true;
                        q.push_back((*i));
                        hc[*i]=hc[x]+1;
                    }
                }
            }
        }
};
int main()
{
    int n,i,l,m,x,y;
    cin>>n;
    graph jyoti(n);
    for(i=0;i<n-1;i++)
    {
        cin >>x >>y;
        jyoti.addedge(x,y);
    }
    jyoti.bfs(1);
    map<int,int>::iterator j;
    l = 0;
    m = 1;
    for(j = hc.begin(); j != hc.end(); j++)
    {
        if(j->second > l)
        {
            l = j->second;
            m = j->first;
        }
    }
    jyoti.bfs(m);
    for(j = hc.begin(); j != hc.end(); j++)
    {
        if(j->second > l)
        {
            l = j->second;
        }
    }
    cout << l;
    return 0;
}

