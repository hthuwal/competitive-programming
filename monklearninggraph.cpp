#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <cstdio>
using namespace std;

#define vi vector<int>

class Graph{
private:
    int v;
    vi *list;
    vi value;
public:
    Graph(int v)
    {
        this->v=v;
        list = new vi[v];
        value.assign(v,0);
    }
    
    void addedge(int a,int b)
    {
        list[a].push_back(b);
        list[b].push_back(a);
    }

    void setvalue(int v,int x)
    {
        value[v]=x;    
    }

    int find(int s,int k)
    {
        multiset<pair<int,int> > setds;
        for(int i=0;i<list[s].size();i++)
        {
            setds.insert(make_pair(value[list[s][i]],list[s][i]));
        }
        multiset<pair<int,int> >::iterator it = setds.end();
        if(k<=setds.size() && k>0)
        {
            for(int i=0;i<k;i++)
            {
                it--;
            }
            return (*it).second+1;
        }
        else
            return -1;
    }
};
int main()
{
    freopen("in.txt","r",stdin);
    int n,m,k,value,x,y;
    cin>>n>>m>>k;
    Graph g(n);
    for(int i=0;i<n;i++)
    {
        cin>>value;
        g.setvalue(i,value);
    }
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        g.addedge(--x,--y); 
    }
    for(int i=0;i<n;i++)
    {
        cout<<g.find(i,k)<<"\n";
    }
}