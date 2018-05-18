#include <iostream>
#include <cstdio>
using namespace std;
typedef struct node{
    int value;
    struct node* next;
} node;

typedef struct linklist{
    node* head=NULL;
} linklist;

void insert(linklist *ll,int a)
{
    node * x = new node;
    x->value=a;
    x->next=NULL;
    if(ll->head==NULL)
        ll->head=x;
    else
    {
        x->next=ll->head;
        ll->head=x;
    }
}

typedef struct Graph{
    int V;
    linklist *list;
} Graph;

void initGraph(Graph *g,int v)
{
    g->V=v;
    g->list = new linklist[v];
}

void addedge(Graph *g,int a,int b)
{
    insert(&(g->list[a]),b);
    insert(&(g->list[b]),a);
}

void printgraph(Graph g)
{
    for(int i=0;i<g.V;i++)
    {
        cout<<i<<": ";
        node* temp = g.list[i].head;
        while(temp!=NULL)
        {
            cout<<temp->value<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
}
int modifiedbfs(Graph g,int s,int visited[])
{
    int v=g.V;
    int q[v*v];
    int f = 0;
    int r = 0;

    visited[s]=0;
    q[r++]=s;
    while(f<r)
    {
        int front = q[f++];
        node *temp = g.list[front].head;
        while(temp!=NULL)
        {
            int nbr = temp->value;
            if(visited[nbr]==-1)
            {
                visited[nbr]=1-visited[front];
                q[r++]=nbr;
            }
            else if(visited[nbr]==visited[front])
                return -1;
            
            temp=temp->next;
        }
    }
    return 1;
}

int is2colorable(Graph g)
{
    int v = g.V;
    int visited[v];
    for(int i=0;i<v;i++)visited[i]=-1;

    for(int i=0;i<v;i++)
    {
        if(visited[i]==-1)
        {
            if(modifiedbfs(g,i,visited)==-1)
                return -1;
        }
    }
    return 1;
}
int main()
{   
    freopen("in.txt","r",stdin);
    int t,v,e,a,b;
    cin>>t;
    while(t--)
    {
        cin>>v>>e;
        Graph g;
        initGraph(&g,v);
        for(int i=0;i<e;i++)
        {
            cin>>a>>b;
            a--;b--;
            addedge(&g,a,b);
        }
        cout<<is2colorable(g);
    }
}