#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
#define N 111111
#define LN 24
vector<int> adj[N];
vector<int> magic[N];
int firstoccur[N],eulertour[10011001],euler;
int lookup[10011001][LN];
int parent[N];
 
void preprocess(int n)
{
    for(int i=0;i<n;i++)
        lookup[i][0]=i;
    
    for(int j=1;(1<<j)<=n;j++)
    {
        for(int i=0;(i+(1<<j)-1)<n;i++)
        {
            if(eulertour[lookup[i][j-1]] < eulertour[lookup[i+(1<<(j-1))][j-1]])
                lookup[i][j]=lookup[i][j-1];
            else
                lookup[i][j]=lookup[i+(1<<(j-1))][j-1];
        }
    }
}
int RMQ(int L,int R)
{
    int k = (int)log2(R-L+1);
    if(eulertour[lookup[L][k]]<eulertour[lookup[R-(1<<k)+1][k]])
        return eulertour[lookup[L][k]];
    else
        return eulertour[lookup[R-(1<<k)+1][k]];
}
int lca(int a,int b)
{
    if(firstoccur[b]<firstoccur[a])
    {
        int temp=a;
        a=b;
        b=temp;
    }
    return RMQ(firstoccur[a],firstoccur[b]);
}
void dfs(int now,int prev)
{
    parent[now]=prev;
    firstoccur[now]=euler;
    eulertour[euler++]=now;
    for(int i=0;i<adj[now].size();i++)
    {
        if(adj[now][i]!=prev)
        {
            dfs(adj[now][i],now);
            eulertour[euler++]=now;
        }
    }
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
            firstoccur[i]=-1;
            parent[i]=-1;
            adj[i].clear();
            magic[i].clear();
        }
        euler=0;
        for(int i=0;i<n-1;i++)
        {
            scanf("%d %d %d",&u,&v,&c);
            adj[--u].push_back(--v);
            magic[u].push_back(c);
            adj[v].push_back(u);
            magic[v].push_back(c);        
        }
        dfs(0,-1);
        preprocess(euler);
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&u,&v,&c);
            int p= lca(--u,--v),x,hc=0;
 
            while(u!=p)
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
            while(v!=p)
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
            printf("%d\n",hc);
        }
    }   
} 