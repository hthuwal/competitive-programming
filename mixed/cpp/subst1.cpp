#include <iostream>
#include <string>
#define B 26
using namespace std;

typedef struct node{
	char c;
	node * childs[B];
} node;

node* newnode(char c)
{
	node* temp = new node;
	temp->c = c;
	for(int i=0;i<B;i++)
		temp->childs[i]=NULL;

	return temp;
}

void insert(node* head, string str)
{
	if(str=="")
		return;
	
}