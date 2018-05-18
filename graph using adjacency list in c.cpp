/**
 * Graph representation using adjacency list.
 * adjacency list is implemented as an array of linkedlists
 */
#include <cstdio>
#include <cstdlib>

/*
Defining Node Datatype
 */
typedef struct node{
	int value;
	struct node* next=NULL;
} node;

/*
Defining linklist Datatype
 */
typedef struct linklist{
	node* head=NULL;
} linklist;

/*
Defining graph datatype
 */
typedef struct graph{
	int v;
	linklist* list=NULL;
} graph;

/*
Function to create a new node in heap
 */
node* createnode(int value)
{
	node* x = (node *)malloc(sizeof(node));
	x->value = value;
	x->next = NULL;
}

/*
Function to insert at the beginning of the linklist
 */
void llinsert(linklist *ll,int value)
{
	node* x = createnode(value);
	x->next = ll->head;
	ll->head = x;
}
/*
Function to delete the last element of linklist
 */
void lldelend(linklist *ll)
{
	node *ptr = ll->head;
	if(ptr!=NULL)
	{
		if(ptr->next==NULL)
		{
			free(ptr);	
			ll->head=NULL;
		}	
		else
		{
			while(ptr->next->next!=NULL)
				ptr=ptr->next;

			free(ptr->next);
			ptr->next=NULL;
		}
	}

}

/*
Function to initialize the graph
 */
void initgraph(graph* g,int vertices)
{
	g->v = vertices;
	g->list = (linklist*)malloc(sizeof(linklist)*vertices);
}

/*
Function to add edge in graph
 */
void addedge(graph *g,int s, int d)
{
	llinsert(&(g->list[s]),d);
}

/*
Function to print graph in adjacency representation
 */
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
int main()
{
	graph g;
	initgraph(&g,4);
	addedge(&g,0,1);
	addedge(&g,2,2);
	addedge(&g,0,3);
	printgraph(g);
}