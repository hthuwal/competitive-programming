#include <cstdio>
#include <vector>
using namespace std;

#define root 0
#define N 11111
#define LOG2N 14

int st[6*N],baseArray[N];//forsegment tree
int parent[N],subsize[N],depth[N],deep_of_edge[N];//during dfs
vector<int> adj[N],weights[N],edgeno[N];//for reading graph
int curChain,chainId[N],chainHead[N],posinBase[N],ptr;//for hld

/********************************************************
Segment Tree
********************************************************/

/*create segment tree*/
void create_st(int ti,int l,int h)
{
    if(l==h)
        st[ti]=baseArray[l];
    else
    {
        int mid = (l+h)>>1;
        int left = ti<<1;
        int right = left | 1;
        create_st(left,l,mid);
        create_st(right,mid+1,h);
        st[ti] = st[left] > st[right] ? st[left] : st[right];
    }
}

/*update tree*/
void update_st(int ti,int l,int h,int x,int value)
{
    if(x<l || x>h) return;
    if(l==h && l==x) st[ti]=value;
    else
    {
        int mid = (l+h)>>1;
        int left = ti<<1;
        int right = left | 1;
        update_st(left,l,mid,x,value);
        update_st(right,mid+1,h,x,value);
        st[ti] = st[left] > st[right] ? st[left] : st[right];
    }
}

/*getmax for range*/
int getmax_st(int ti,int l,int h,int ql,int qh)
{
    if(ql>h || qh <l) return 0;
    if(ql<=l && qh>=h) return st[ti];
    int mid = (l+h)>>1, left = ti<<1,right = left|1;
    int left_max = getmax_st(left,l,mid,ql,qh);
    int right_max = getmax_st(right,mid+1,h,ql,qh);
    return (left_max > right_max ? left_max : right_max);
}

/***********************************************************
DFS
***********************************************************/
void dfs(int now,int prev,int tobe_depth)
{
    parent[now]=prev;
    depth[now]=tobe_depth;
    subsize[now]=1;
    for(int i=0;i<adj[now].size();i++)
    {
        if(adj[now][i]!=prev)
        {
            deep_of_edge[edgeno[now][i]]=adj[now][i];
            dfs(adj[now][i],now,tobe_depth+1);
            subsize[now]+=subsize[adj[now][i]];
        }
    }
}

/***********************************************************
Heavy Light Decomposition
***********************************************************/
void hld(int now,int weight,int prev)
{
    if(chainHead[curChain]==-1) chainHead[curChain]=now;

    chainId[now]=curChain;
    posinBase[now]=ptr;
    baseArray[ptr++]=weight;

    int special_child=-1,weightforsc;

    for(int i=0;i<adj[now].size();i++)
    {
        if(adj[now][i]!=prev)
        {
            if(special_child ==-1 || 
            subsize[special_child]<subsize[adj[now][i]]){
                special_child=adj[now][i];
                weightforsc = weights[now][i];
            }
        }
    }
    // printf("w %d ",weightforsc);
    if(special_child!=-1)
        hld(special_child,weightforsc,now);

    for(int i=0;i<adj[now].size();i++)
    {
        if(adj[now][i]!=prev && adj[now][i]!=special_child)
        {
            curChain++;
            hld(adj[now][i],weights[now][i],now);
        }
    }
}
/***********************************************************
Query and update in HLD
***********************************************************/
int query_up(int a,int b)
{
    if(a==b) return 0;
    int achain,bchain=chainId[b],ans=-1;
    while(1){
        achain=chainId[a];
        if(achain==bchain){
            if(a==b) break;
            int x = getmax_st(1,0,ptr-1,posinBase[b]+1
                    ,posinBase[a]);
            if(x>ans) ans=x;
            break;
        }
        int x = getmax_st(1,0,ptr-1,posinBase[chainHead[achain]]
                ,posinBase[a]);
        if(x>ans) ans=x;
        a=parent[chainHead[achain]];
    }
    return ans;
}
int lca(int a,int b)
{
    vector<int> lca_aux(ptr+5,-1);
    if(depth[a]<depth[b]){
        int t=a;
        a=b;
        b=t;
    }
    while(a!=-1){
        lca_aux[a]=1;
        a=parent[a];
    }
    while(1)
    {
        if(lca_aux[b]==1)   break;
        b=parent[b];
    }
    return b;
}
int query(int a,int b)
{
    int lc = lca(a,b);
    int c1=query_up(a,lc);
    int c2=query_up(b,lc);
    if(c1>c2) c2=c1;
    printf("%d\n",c2);
}
void change(int a,int val)
{
    int v = deep_of_edge[a];
    update_st(1,0,ptr-1,posinBase[v],val);
}
/*************************************************************
*************************************************************/
int main()
{
    freopen("in.txt","r",stdin);
    int t;
    for(scanf("%d",&t);t--;)
    {
        int n,a,b,c;
        scanf("%d",&n);
        /*clearing for new testcase*/
        ptr=0;curChain=0;
        for(int i=0;i<n;i++)
        {
            adj[i].clear(); weights[i].clear();edgeno[i].clear();
            chainHead[i]=-1;
            parent[i]=-1;
        }
        for(int i=1;i<n;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            a--;b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
            weights[a].push_back(c);
            weights[b].push_back(c);
            edgeno[a].push_back(i);
            edgeno[b].push_back(i);
        }
        dfs(0,-1,0);
        /*Checking DFS
        printf("Adjacency List\n");
        for(int i=0;i<n;i++){
            printf("|%d| ",i+1);
            for(int j=0;j<adj[i].size();j++)
                printf("%d,%d ",adj[i][j]+1,weights[i][j]);
            printf("\n");
        }

        printf("\nDepth of Every Node\n");
        for(int i=0;i<n;i++)
            printf("%d %d\n",i+1,depth[i]);

        printf("\nSubsize of Every Node\n");
        for(int i=0;i<n;i++)
            printf("%d %d\n",i+1,subsize[i]);
        
        printf("\nParent of Every Node\n");
        for(int i=0;i<n;i++)
            printf("%d %d\n",i+1,parent[i]+1);
        */
        hld(0,-1,-1);
        /*Checking HLD
        printf("BaseArray\n");
        for(int i=0;i<ptr;i++)
            printf("%d ",baseArray[i]);
        printf("\nPosinBase\n");
        for(int i=0;i<ptr;i++)
            printf("%d ",posinBase[i]);
        printf("\nChainId\n");
        for(int i=0;i<ptr;i++)
            printf("%d ",chainId[i]);
        */           
        create_st(1,0,n-1);
        /*Checking St
        printf("Segment Tree\n");
        for(int i=0;i<3*n;i++)
            printf("%d ",st[i]); 
        */
        char s[10];
        while(1){
            scanf("%s",s);
            if(s[0]=='D') break;
            scanf("%d %d",&a,&b);
            if(s[0]=='Q')
                query(--a,--b);
            else    
                change(a,b);
        }
    }
    /*Checking Segment Tree
    for(int i=0;i<5;i++)
        baseArray[i]=i+1;
    create_st(1,0,4);
    for(int i=0;i<5;i++)
        printf("%d ",baseArray[i]);
    printf("\n");
    for(int i=0;i<10;i++)
        printf("%d ",st[i]);
    printf("%d",getmax_st(1,0,4,3,3));
    update_st(1,0,4,2,8);
    printf("%d",getmax_st(1,0,4,2,4));
    */
}