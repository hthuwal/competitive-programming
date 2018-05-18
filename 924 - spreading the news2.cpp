#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int value;
	struct node* next;
} node;

typedef struct linklist{
	node* head=NULL;
} linklist;

typedef struct graph{
	int v;
	linklist *list;
}graph;

void insert(linklist *ll,int x){		
	node *temp = (node *)malloc(sizeof(node));
	temp->value = x;
	temp->next = ll->head;
	ll->head = temp;
}

void initgraph(graph *g,int v)
{
	g->v=v;
	g->list = (linklist*)malloc(sizeof(linklist)*v);
}

void addedge(graph *g,int a,int b)
{
	insert(&(g->list[a]),b);
}

void printgraph(graph g)
{
	for(int i=0;i<g.v;i++)
	{
		node *ptr = g.list[i].head;
		while(ptr!=NULL)
		{
			printf("%d ",ptr->value);
			ptr=ptr->next;
		}
		printf("\n");
	}
}

void initialize(int a[],int v,int n)
{
	for(int i=0;i<n;i++)
		a[i]=v;
}

void hc(graph g,int s)
{
	int v = g.v;
	int visited[v];
	initialize(visited,-1,v);
	int q[v*20];
	int f=0,r=0;
	q[r++]=s;
	visited[s]=0;
	while(f<r)
	{
		int front  = q[f++];
		int day = visited[front]+1;
		node *temp = g.list[front].head;
		while(temp!=NULL)
		{
			int friendx = temp->value;
			if(visited[friendx]==-1)
			{
				visited[friendx]=day;
				q[r++]=friendx;
			}
			temp=temp->next;
		}
	}
	int hash[v];
	initialize(hash,0,v);
	for(int i=0;i<v;i++)
	{
		if(visited[i]!=-1)
		{
			hash[visited[i]]++;
		}
	}
	int max=-1,p=-1;
	for(int i=0;i<v;i++)
	{
		if(hash[i]>max)
		{	
			max=hash[i];
			p=i;
		}
		else if(p==0 && hash[i]==max && max==1)
		{
			p=i;
		}
	}
	if(p==0)
		printf("0\n");
	else
		printf("%d %d\n",max,p);
}

int main()
{
	freopen("in.txt","r",stdin);
	graph g;
	int v,n,x,t;
	scanf("%d",&v);
	initgraph(&g,v);
	for(int i=0;i<v;i++)
	{
		scanf("%d",&n);
		for(int j=0;j<n;j++)
		{
			scanf("%d",&x);
			addedge(&g,i,x);
		}
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&x);
		hc(g,x);
	}
}