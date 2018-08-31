#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
#define N 1100
#define LN 11
vector<int> adj[N];
int eulertour[3*N],euler;
int firstoccur[N];
int lookup[3*N][3*LN];

void preprocess(int n)
{
    for(int i=0;i<n;i++)
        lookup[i][0]=i;
    
    for(int j=1; (1<<j)<=n;j++)
        for(int i=0;(i+(1<<j)-1)<n;i++)
            if( eulertour[ lookup[i][j-1] ] < 
                eulertour[ lookup[i+(1<<(j-1))][j-1] ])
                lookup[i][j]=lookup[i][j-1];
            else
                lookup[i][j]=lookup[i+(1<<(j-1))][j-1];
}
int RMQ(int L,int R)
{
    int j = (int)log2(R-L+1);
    if( eulertour[ lookup[L][j] ] < eulertour[ lookup[R-(1<<j)+1][j] ])
        return eulertour[ lookup[L][j] ];
    else
        return eulertour[ lookup[R-(1<<j)+1][j] ];
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
int lca(int a,int b)
{
    if(firstoccur[b]<firstoccur[a])
    {
        int temp=a;
        a=b;
        b=temp;
    }
    // printf("#%d %d#",a,b);
    return RMQ(firstoccur[a],firstoccur[b]);
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
            firstoccur[i]=-1;
        }
        euler=0;
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
        preprocess(euler);
        // for(int i=0;i<euler;i++)
        //     printf("%d ",eulertour[i]+1);
        // printf("\n");
        // for(int i=0;i<n;i++)
        //     printf("%d ",firstoccur[i]);
        for(scanf("%d",&q);q--;)
        {
            scanf("%d %d",&a,&b);
            printf("%d\n",lca(--a,--b)+1);
        }

    }
}