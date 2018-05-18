#include <iostream>
#include <vector>
#include <cstdio>
#include <climits>
#include <set>
#include <queue>
#include <utility>

#define INF INT_MAX

using namespace std;

class Graph{
private:
    int v;
    vector<int> *list;
    vector<int> energy;
public:
    Graph(int v)
    {
        this->v=v;
        list = new vector<int> [v];
        energy.assign(v,0);
    }
    void addedge(int a,int b)
    {
        list[a].push_back(b);
    }
    void addenergy(int i,int e)
    {
        energy[i]=e;
    }
    void printgraph()
    {
        for(int i=0;i<v;i++)
        {
            cout<<i+1<<": ";
            for(int j=0;j<list[i].size();j++)
                cout<<list[i][j]+1<<" ";
            cout<<endl;
        }
    }
    int bfs(int s,int d)
    {
        vector<bool> visited(v,false);
        queue<pair<int,int> > q;
        visited[s]=true;      
        q.push(make_pair(s,-100));
        while(!q.empty())
        {
            pair<int,int> t = q.front();q.pop();
            int front  = t.first;
            int e = t.second;            
            for(int i=0;i<list[front].size();i++)
            {
                if(e<0)
                {   
                    if(list[front][i]==d)
                    {
                        return 1;
                    }
                    if(!visited[list[front][i]])
                    {
                        visited[list[front][i]]=true;
                        q.push(make_pair(list[front][i],e+energy[list[front][i]]));
                    }
                }
            }
        }  
        return 0; 
    }
    void bellmanford(int s,int d)
    {
        vector<int> hc(v,INF);
        vector<int> ad(v,-1);
        hc[s]=-100;
        for(int i=0;i<v-1;i++)
        {
            for(int j=0;j<v;j++)
            {
                for(int k=0;k<list[j].size();k++)
                {
                    if(hc[j]!=INF && hc[j]+energy[list[j][k]]<hc[list[j][k]])
                    {
                        hc[list[j][k]]=hc[j]+energy[list[j][k]];
                        ad[list[j][k]]=j;
                    }
                }
            }
        }
        vector<int> aadi(hc);
        for(int j=0;j<v;j++)
        {
            for(int k=0;k<list[j].size();k++)
            {
                if(hc[j]!=INF && hc[j]+energy[list[j][k]]<hc[list[j][k]])
                {
                    hc[list[j][k]]=hc[j]+energy[list[j][k]];
                }
            }
        }
        if(hc==aadi)
        {
            int t =d,flag=1;
            while(t!=s)
            {
                if(hc[t]>=0)
                {
                    flag=0;break;
                }
                t=ad[t];
            }
            if(flag==1)
                cout<<"winnable\n";
            else
                cout<<"hopeless\n";
        }
        else if(hc[d]!=INF)
        {
            set<int> st;
            int t=-1;
            for(int i=0;i<v;i++)
            {
                if(hc[i]!=aadi[i] && aadi[i]>=0)
                {
                    cout<<"hopeless\n";
                    break;
                }
            }
            cout<<"winnable\n";
        }
        else
            cout<<"hopeless\n";
    }
  
};

int main()
{
    freopen("in.txt","r",stdin);
    int n,a,b,c;
    while(1)
    {
        cin>>n;
        if(n==-1)
            break;
        else
        {
            int s=-1,d=-1;
            Graph g(n);
            for(int i=0;i<n;i++)
            {
                cin>>a;
                if(a==0 && s==-1)
                    s=i;
                else if(a==0 &&d==-1)
                    d=i;
                g.addenergy(i,a*(-1));
                cin>>b;
                for(int j=0;j<b;j++)
                {
                    cin>>c;
                    g.addedge(i,--c);
                }
            }
            g.bellmanford(s,d);
        }
     
    }
}