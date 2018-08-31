#include <cstdio>
#include <vector>
using namespace std;
#define N 1100
vector<int> adj[N];
int parent[N];
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
int lca(int a,int b,int n)
{
    int lca_path[n];
    for(int i=0;i<n;i++)
        lca_path[i]=-1;
    while(a!=-1)
    {
        lca_path[a]=1;
        a=parent[a];
    }
    while(1)
    {
        if(lca_path[b]==1)
            break;
        b=parent[b];
    }
    return b;
}
int main()
{
    freopen("in.txt","r",stdin);
    int k,t,n,q,e,v,a,b;
    scanf("%d",&t);
    for(k=1;k<=t;k++)
    {
        printf("Case %d:\n",k);
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            adj[i].clear(); 
            parent[i]=-1;
        }
        for(int i=0;i<n;i++)
        {
            for(scanf("%d",&e);e--;)
            {
                scanf("%d",&v);
                adj[i].push_back(--v);
                adj[v].push_back(i);
            }
        }
        dfs(0,-1);
        // for(int i=0;i<n;i++)
        //     printf("%d ",parent[i]+1);
        for(scanf("%d",&q);q--;)
        {
            scanf("%d %d",&a,&b);
            printf("%d\n",lca(--a,--b,n)+1);
        }

    }
}