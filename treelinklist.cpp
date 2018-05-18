#include<iostream>
using namespace std;
struct node{
	int x;
	node *left;
	node *right;
};
node* start;
int count=1;
node* newnode(int x)
{
	node* temp = new node;
	temp->x=x;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
node* insert(node* hc,int x,int t)
{
	if(hc==NULL)
	{
		hc=newnode(x);
		count++;
	}
	else
	{
		if(t%2==0)
			hc->left=insert(hc->left,x,t/2);
		else
			hc->right=insert(hc->right,x,t/2);
	}
	return hc;
}

void inorder(node* hc)
{
	if(hc!=NULL)
	{
		inorder(hc->left);
		cout<<hc->x<<" ";
		inorder(hc->right);
	}
}
int main()
{
	int a,x;
	start=NULL;
	while(1)
	{
		cout<<"1.Insert\n2.Inorder\n";
		cin>>a;
		switch(a)
		{
			case 1: cout<<"Enter element to be inserted:";
					cin>>x;
					start=insert(start,x,count);
					break;
			case 2: inorder(start);
			       break;
			case 3: return 1;
		}
	}
}