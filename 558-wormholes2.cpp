#include <cstdio>
#include <cstdlib>
#include <climits>
#define INF (INT_MAX-2000)

typedef struct node{
    int v;
    int w;
    struct node* next=NULL;
} node;

typedef struct linklist{
    node *head=NULL;
} linklist;

void llinsert(linklist *ll,int a,int b)
{
    node *x = (node*)malloc(sizeof(node));
    x->v=a;
    x->w=b;
    x->next=ll->head;
    ll->head=x;
}

typedef struct Graph{
    int v;
    linklist *list=NULL;
} graph;

void initgraph(graph *g,int v)
{
    g->v=v;
    g->list = (linklist*)malloc(sizeof(linklist)*v);
}

void addedge(graph *g,int a,int b,int w)
{
    llinsert(&(g->list[a]),b,w);
}

void bellmanford(graph g)
{
    int hc[g.v];
    for(int i=0;i<g.v;i++)
        hc[i]=INF;
    hc[0]=0;
    for(int i=0;i<g.v-1;i++)
    {
        for(int j=0;j<g.v;j++)
        {
            node* temp = g.list[j].head;
            for(;temp!=NULL;temp=temp->next)
            {
                int p = temp->v;
                int w = temp->w;
                if(hc[p]>hc[j]+w)
                    hc[p]=hc[j]+w;
            }
        }
    }
    int aadi[g.v];
    for(int i=0;i<g.v;i++)
        aadi[i]=hc[i];
    for(int j=0;j<g.v;j++)
    {
        for(node* temp = g.list[j].head;temp!=NULL;temp=temp->next)
        {
            int p = temp->v;
            int w = temp->w;
            if(hc[p]>hc[j]+w)
                hc[p]=hc[j]+w;
        }
    }
    int flag=1;
    for(int i=0;i<g.v;i++)
    {
        if(hc[i]!=aadi[i])
        {
            flag=0;
            break;
        }
    }
    if(flag==1)
        printf("not possible\n");
    else 
        printf("possible\n");
}
int main()
{
    freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,a,b,c;
        scanf("%d %d",&n,&m);
        Graph g;
        initgraph(&g,n);
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            addedge(&g,a,b,c);
        }
        // printgraph(g);
       bellmanford(g);
    }
}