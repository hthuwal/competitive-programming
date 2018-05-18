#include <cstdio>
#include <cstdlib>

typedef struct path{
	int value;
	int p;
	struct path* next;
} path;

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
		printf("%d: ",i+1);
		node *ptr = g.list[i].head;
		while(ptr!=NULL)
		{
			printf("%d ",ptr->value+1);
			ptr=ptr->next;
		}
		printf("\n");
	}
}

int iscolorableB(graph *g,int x,int color[])
{
	node * head = g->list[x].head;
	for(;head!=NULL;head=head->next)
	{
		if(color[head->value]==-1)
			return 0;
	}
	return 1;
}

path* backtracking(graph *g,int x,int color[])
{
	if(x<(g->value))
	{
		path *black,*white,*ad;
		
		node *temp = g->list[x].head;
		int flag=1;
		while(temp!=NULL)
		{
			if(color[temp->value]==-1)
			{
				flag=0;
				break;
			}
			temp=temp->next;
		}
		
		color[x]=1;
		white = backtracking(g,x+1,color);

		if(flag==1)
		{
			color[x]=-1;
			black = backtracking(g,x+1,color);
			if((black->value + 1)>(white->value))
			{
				path* temp = (path *)malloc(sizeof(path));
				temp->value = black->value +1;
				temp->p = x;
				temp->next = black;
				return temp;
			}
			else
			{
				return white;
			}
		}
		else
		{
			return white;
		}
		
	}
	path *t = (path*)malloc(sizeof(path));
	t->value=0;
	t->p=-1;
	t->next=NULL;
	return t;
}

int main()
{
	freopen("in.txt","r",stdin);
	int m,n,k,a,b;
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d %d",&n,&k);
		graph g;
		initgraph(&g,n);
		for(int i=0;i<k;i++)
		{
			scanf("%d %d",&a,&b);
			addedge(&g,--a,--b);
		}
		int color[n];
		for(int i=0;i<n;i++)
			color[i]=0;

		path *t = backtracking(&g,0,color);
		// printgraph(g);
		printf("%d\n",t->value);
		while(1)
		{
			if(t->next==NULL)
				break;
			if(t->next->next==NULL)
			{
				printf("%d\n",t->p+1);
				break;
			}
			printf("%d ",t->p+1);
			t=t->next;
		}
		
	}
}
