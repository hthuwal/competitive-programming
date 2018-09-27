#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
#define N 111111
#define LN 24
vector<int> adj[N];
vector<int> magic[N];

int parent[N];
int parentedge[N];

void dfs(int now,int prev)
{
    parent[now]=prev;

    for(int i=0;i<adj[now].size();i++)
    {
        if(adj[now][i]!=prev)
        {
            dfs(adj[now][i],now);
        }
    }
}
int lca(int a,int b,int c,int n)
{
    vector<int> lca_aux(n+5,-1);
    int u=a,v=b,x;
    while(a!=-1){
        lca_aux[a]=1;
        a=parent[a];
    }
    while(1)
    {
        if(lca_aux[b]==1)   break;
        b=parent[b];
    }
    int hc=0;
    // printf("lca of %d and %d is %d\n",x,y,b);
    while(u!=b)
    {
        x=parent[u];
        int i;
        for(i=0;i<adj[u].size();i++)
        if(adj[u][i]==x)break;
        if(magic[u][i] <= c)
        {
            // printf("%d ",magic[u][i]);
            hc=hc^magic[u][i];
        }
        u=parent[u];
    }
    while(v!=b)
    {
        x=parent[v];
        int i;
        for(i=0;i<adj[v].size();i++)
        if(adj[v][i]==x)break;
        if(magic[v][i] <= c)
        {
            // printf("%d ",magic[v][i]);
            hc=hc^magic[v][i];
        }
        v=parent[v];
    }
    return hc;
}
int main()
{
    freopen("in.txt","r",stdin);
    int t,n,u,v,c,m;
    for(scanf("%d",&t);t--;)
    {
        scanf("%d",&n);
        for(int i=0;i<=n;i++)
        {
            parent[i]=-1;
            parentedge[i]=-1;
            adj[i].clear();
            magic[i].clear();
        }
        for(int i=0;i<n-1;i++)
        {
            scanf("%d %d %d",&u,&v,&c);
            adj[--u].push_back(--v);
            magic[u].push_back(c);
            adj[v].push_back(u);
            magic[v].push_back(c);        
        }
        dfs(0,-1);
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&u,&v,&c);
            printf("%d\n",lca(--u,--v,c,n));
           
        }
    }   
}