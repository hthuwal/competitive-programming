#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
#define N 10100
#define LN 24

vector<int> adj[N];
int eulertour [10011001],euler,firstoccur[N];
int lookup[10011001][LN];
void preprocess(int n)
{
    for(int i=0;i<n;i++)
        lookup[i][0]=i;
    
    for(int j=1;(1<<j)<=n;j++)
        for(int i=0;(i+(1<<j)-1)<n;i++)
            if(eulertour [ lookup[i][j-1]] <
               eulertour [ lookup[i+(1<<(j-1))][j-1] ])
               lookup[i][j]=lookup[i][j-1];
            else
                lookup[i][j]=lookup[i+(1<<(j-1))][j-1];
}
int RMQ(int L,int R)
{
    int j = (int)log2(R-L+1);
    if(eulertour[lookup[L][j]] < eulertour[ lookup[R-(1<<j)+1][j]] )
        return eulertour[lookup[L][j]];
    else
        return eulertour[lookup[R-(1<<j)+1][j]];
}
int lca(int a,int b)
{
    if(firstoccur[b]<firstoccur[a])
    {
        int temp = a;
        a=b;
        b=temp;
    }
    return RMQ(firstoccur[a],firstoccur[b]);
}
void dfs(int now,int prev)
{
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
    int n,e,v,q,a,b;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        adj[i].clear(); 
        firstoccur[i]=-1;
    }
    euler=0;
    for(int i=0;i<n;i++)
    {
        for(scanf("%d",&e);e--;)
        {
            scanf("%d",&v);
            adj[i].push_back(v);
            adj[v].push_back(i);
        }
    }
    dfs(0,-1);
    preprocess(euler);
    for(scanf("%d",&q);q--;)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",lca(a,b));
    }
    // printf("Euler Tour\n");
    // for(int i=0;i<euler;i++)
    // printf("%d ",eulertour[i]);
    // printf("First Occurences\n");
    // for(int i=0;i<n;i++)
    // printf("%d ",firstoccur[i]);
}
