#include <iostream>
#include <set>
#include <vector>
#include <cstdio>
#include <utility>
#include <climits>
#define INF (INT_MAX-2100)
#define vi vector<pair<int,int> >
using namespace std;
class Graph{
private:
    int v;
    vector<pair<int,int> > *list;
public:
    Graph(int v)
    {
        this->v=v;
        list = new vi[v];
    }
    void addedge(int a,int b,int w)
    {
        list[a].push_back(make_pair(b,w));
    }
    void print(vector<int> x)
    {
        for(int i=0;i<x.size();i++)
            cout<<x[i]<<" ";
        cout<<"\n";
    }
    int bellmanford()
    {
        vector<int> hc(v,INF);
        hc[0]=0;
        for(int i=0;i<v-1;i++)
        {
            for(int j=0;j<v;j++)
            {
                for(int k=0;k<list[j].size();k++)
                {
                    int n = hc[j]+list[j][k].second;
                    int p = list[j][k].first;
                    if(hc[p]>n)
                        hc[p]=n;
                }
            }
           
        }
        vector<int> aadi(hc);
        for(int j=0;j<v;j++)
        {
            for(int k=0;k<list[j].size();k++)
            {
                int n = hc[j]+list[j][k].second;
                int p = list[j][k].first;
                if(hc[p]>n)
                    hc[p]=n;
            }
        }
        if(aadi==hc)
            cout<<"not possible\n";
        else
            cout<<"possible\n";
    }
};
int main()
{
    freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,a,b,c;
        cin>>n>>m;      
        Graph g(n);
        for(int i=0;i<m;i++)
        {
            cin>>a>>b>>c;
            g.addedge(a,b,c);
        }
        g.bellmanford();
    }
}