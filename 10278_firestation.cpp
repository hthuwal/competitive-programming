/*input
2

1 6
2
1 2 10
2 3 10
3 4 10
4 5 10
5 6 10
6 1 10

1 6
2
1 2 10
2 3 10
3 4 10
4 5 10
5 6 10
6 1 10
*/
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <sstream>
using namespace std;
typedef struct heapnode{
	int vertex;
	int distance;
} heapnode;

typedef struct node{
	int value;
	int vajan;
	struct node* next=NULL;
} node;

typedef struct linklist{
	int n;
	node *head =NULL;
} linklist;

typedef struct graph{
	int v;
	linklist *list = NULL;
} graph;

void maxheapify(heapnode a[],int i,int n)
{
	int left = 2*i;
	int right = 2*i+1;
	int smallest;
	if(left<=n && a[left].distance<a[i].distance)
		smallest=left;
	else
		smallest=i;

	if(right<=n && a[right].distance<a[smallest].distance)
		smallest=right;

	if(smallest!=i)
	{
		heapnode temp = a[i];
		a[i]=a[smallest];
		a[smallest]=temp;
		maxheapify(a,smallest,n);
	}
}

heapnode deleteheap(heapnode a[],int n)
{
	heapnode ans = a[1];
	a[1]=a[n];
	maxheapify(a,1,n-1);
	return	ans;
}
void buildheap(heapnode a[],int n)
{
	for(int i=n/2;i>=1;i--)
	{
		maxheapify(a,i,n);
	}
}
void update(heapnode a[],int v,int x,int n)
{
	for(int i=1;i<=n;i++)
	{
		if(a[i].vertex==v)
		{
			if(a[i].distance>x)
				a[i].distance=x;
			break;
		}
	}
	buildheap(a,n);
}


node* createnode(int v,int q)
{
	node *x = (node*)malloc(sizeof(node));
	x->value=v;
	x->vajan=q;
	x->next=NULL;
	return x;
}

void llinsert(linklist *ll,int v,int q)
{
	if(ll->head==NULL)
		ll->n=0;
	node *x = createnode(v,q);
	x->next = ll->head;
	ll->head = x;
	(ll->n)++;
}
void lldelete(linklist *ll)
{
	if(ll->head!=NULL)
	{
		node* temp = ll->head;
		ll->head = temp->next;
		free(temp);
	}
}
void initgraph(graph *g,int v)
{
	g->v=v;
	g->list = (linklist*)malloc(sizeof(linklist)*v);
}

void addedge(graph *g,int a,int b,int q)
{
	llinsert(&(g->list[a]),b,q);
	llinsert(&(g->list[b]),a,q);
}

int dijsktra(graph g,int source)
{
	int ans=0;
	int n = g.v-1;
	heapnode dist[n+1];
	for(int i=1;i<=n;i++)
	{
		dist[i].vertex=i;
		dist[i].distance=INT_MAX;
	}
	dist[source].distance=0;
	buildheap(dist,n);
	while(n>0)
	{
		heapnode hc = deleteheap(dist,n);
		n--;
		{
			// printf("%d %d\n",hc.vertex,hc.distance);
			ans+=hc.distance;
		}
		node* padosi = g.list[hc.vertex].head;
		while(padosi!=NULL)
		{
			update(dist,padosi->value,hc.distance+padosi->vajan,n);
			padosi=padosi->next;
		}
	}
	return ans;
}
int digit(int p)
{
	int x=1;
	while(p!=0)
	{
		x*=10;
		p=p/10;
	}
	x*=10;
	return x;
}
int checke(int a[],int p,int n)
{
	for(int i=0;i<n;i++)
	{
		if(a[i]==p)
			return 1;
	}
	return 0;
}
int main()
{
	int t,f,i,j,k,a,b,c;
	char u;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&f,&i);
		graph g;
		int fire[f];
		initgraph(&g,i+2);
		for(j=0;j<f;j++)
		{
			scanf("%d",&k);
			fire[j]=k;
			addedge(&g,i+1,k,0);
		}
		string str;
    	getline(cin, str);
    	// cout << str;
    	while (getline(cin, str) && !str.empty()) {
      		stringstream ss(str);
      		ss >> a >> b >> c;
      		addedge(&g,a,b,c);
    	}
		
		int min=INT_MAX;
		int p=-1,q;
		for(j=1;j<i;j++)
		{
			if(checke(fire,j,f)==0)
			{
			addedge(&g,i+1,j,0);
			q=dijsktra(g,i+1);
			if(q<min)
			{
				min=q;
				p=j;
			}
			lldelete(&(g.list[i+1]));
			}
		}
		printf("%d\n",p);
		printf("\n");
	}
	
}