#include <cstdio>
#include <cstdlib>
typedef struct node{
	int value;
	struct node* next=NULL;
} node;

typedef struct ll{
	node* head=NULL;
}ll;

typedef struct graph{
	int value;
	ll* list;
} graph;

node* create(int x)
{
	node *p = (node*)malloc(sizeof(node));
	p->value=x;
	p->next=NULL;
	return p;
}

void initgraph(graph *g,int v)
{
	g->value = v;
	g->list = (ll*)malloc(sizeof(ll)*v);
}

void insert(ll *l,int v)
{
	node *x = create(v);
	x->next = l->head;
	l->head=x;
}

void addedge(graph *g,int a,int b)
{
	insert(&(g->list[a]),b);
	insert(&(g->list[b]),a);
}

void printgraph(graph g)
{
	for(int i=0;i<g.value;i++)
	{
		printf("%d: ",i);
		node *ptr = g.list[i].head;
		while(ptr!=NULL)
		{
			printf("%d ",ptr->value);
			ptr=ptr->next;
		}
		printf("\n");
	}
}

void utility(graph *g,int a,int color[],int pre)
{
	color[a]=1-pre;
	node *ptr = g->list[a]->head;
	while(ptr!=NULL)
	{

	}
}
void backtracking(graph *g,int color[])
{
	for(int i=0;i<g.v;i++)
		color[i]=-1;
}

int main()
{
	graph g;
	initgraph(&g,5);
	addedge(&g,0,4);
	addedge(&g,3,1);
	addedge(&g,1,2);
	addedge(&g,0,3);
	printgraph(g);
}
