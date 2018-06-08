/*input
16
10 15 15 20 20 25 10 30 30 47 47 50 25 45 45 65
15 35 35 55 20 40 50 55 35 40 55 60 40 60 60 65
35 2 35 3 0 0
14
1 2 2 7 1 3 3 4 3 5 5 10 5 11
4 6 7 6 7 8 7 9 8 9 8 6 6 11
1 1 1 2 3 2 3 3 0 0
0
*/
#include <cstdio>
#include <cstdlib>
#include <map>
#include <iostream>
using namespace std;

typedef struct pain{
	int x;
	int y;
} pain;
typedef struct node{
	int value;
	struct node* next=NULL;
} node;

typedef struct linklist{
	int n;
	node* head=NULL;
} linklist;

typedef struct graph{
	int v;
	linklist* list=NULL;
} graph;

node* createnode(int value)
{
	node* x = (node *)malloc(sizeof(node));
	x->value = value;
	x->next = NULL;
}

void llinsert(linklist *ll,int value)
{
	node* x = createnode(value);
	if(ll->head==NULL)
		ll->n=0;
	x->next = ll->head;
	ll->head = x;
	(ll->n)++;
}

void initgraph(graph* g,int vertices)
{
	g->v = vertices;
	g->list = (linklist*)malloc(sizeof(linklist)*vertices);
}

void addedge(graph *g,int s, int d)
{
	llinsert(&(g->list[s]),d);
	llinsert(&(g->list[d]),s);
}

void printgraph(graph g)
{
	for(int i=0;i<g.v;i++)
	{
		node *ptr = g.list[i].head;
		printf("%d ",i);
		while(ptr!=NULL)
		{
			printf("%d ",ptr->value);
			ptr=ptr->next;
		}
		printf("\n");
	}
}

int bfs(graph g,int s,int ttl)
{	
	pain a[g.v*g.v];
	int f=0,r=0;
	int count=0;
	int visited[g.v];
	for(int i=0;i<g.v;i++)
	{
		visited[i]=0;
	}
	pain tt;
	tt.x = s;
	tt.y = ttl;
	a[r++]=tt;
	visited[s]=1;
	count++;
	//printf("%d ",s);
	while(f<=r)
	{
		tt = a[f++];
		int front = tt.x;
		int nttl = tt.y;
		nttl--;
		if(nttl>=0)
		{
			node *ptr = g.list[front].head;
			while(ptr!=NULL)
			{
				if(visited[ptr->value]==0)
				{
					visited[ptr->value]=1;
					//printf("%d ",ptr->value);
					tt.x = ptr->value;
					tt.y = nttl;
					a[r++]=tt;
					count++;
				}
				ptr=ptr->next;
			}
		}
	}
	return count;
}
int main()
{
	int n,a,b,i;
	int t=1;
	while(1)
	{
		int n,l=0;
		graph g;
		initgraph(&g,35);
		scanf("%d",&n);
		if(n==0) break;
		map<int,int> hc;
		int c,a,b;
		for(int i=0;i<n;i++)
		{
			cin>>a>>b;
			if(hc.find(a)==hc.end())
			{
				hc[a]=l;l++;
			}
			if(hc.find(b)==hc.end())
			{
				hc[b]=l;l++;
			}
			addedge(&g,hc[a],hc[b]);
		}
		while(1)
		{
			scanf("%d %d",&a,&b);
			if(a==0&&b==0) break;
			int x = bfs(g,hc[a],b);
			x = hc.size()-x;
			cout<<"Case "<<t<<": "<<x<<" nodes not reachable from node "<<a<<" with TTL = "<<b<<".\n";
			t++;
		}
	}
}