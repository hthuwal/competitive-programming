#include <iostream>
#include <cstdio>
using namespace std;
typedef struct node{
    int v;
    struct node* next=NULL;
} node;

typedef struct linklist{
    node* head=NULL;
}linklist;

void add(linklist &ll,int v)
{
    node *p = new node;
    p->v=v;
    p->next =NULL;
    if(ll.head==NULL)
        ll.head=p;
    else
    {
        p->next=ll.head;
        ll.head=p;
    }
}
class Graph{
private:
    int v;
    linklist *list;
public:
    Graph(int v)
    {
        this->v=v;
        list = new linklist[v];
    }
    void addedge(int a,int b)
    {
        add(list[a],b);
        add(list[b],a);
    }
    void print()
    {
        for(int i=0;i<v;i++)
        {
            cout<<i<<": ";
            node*temp = list[i].head;
            while(temp!=NULL)
            {
                cout<<temp->v<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
    bool isBicolorable()
    {
        cout<<"Hello";
        int s = 0;
        int q[v*v],f=0,r=0;

        int visited[v];
        for(int i=0;i<v;i++)
            visited[i]=-1;

        visited[s]=0;
        q[r++]=s;
        while(f<r)
        {
            int front = q[f++];
            node* temp = list[front].head;
            while(temp!=NULL)
            {
                int neigh = temp->v;
                if(visited[neigh]==-1)
                {
                    visited[neigh]=1-visited[front];
                    q[r++];
                }
                else if(visited[neigh]==visited[front])
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n,e,a,b;
        cin>>n;
        Graph g(n);
        cin>>e;
        for(int i=0;i<e;i++)
        {   
            cin>>a>>b;
            g.addedge(a,b);
        }
        cout<<"Hello";
        cout<<g.isBicolorable()<<" ";
    }
}
