/**
 * https://www.hackerrank.com/challenges/swap-nodes-algo
 */

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int index;
	Node* left;
	Node* right;

	Node(int i){
		index = i;
		left = nullptr;
		right = nullptr;
	}
};


void swap(Node* root, int k, int h)
{
	if(root == nullptr)
		return;
	else
	{
		swap(root->left, k, h+1);
		swap(root->right, k, h+1);
		if(h%k==0)
		{
			Node* temp = root->left;
			root->left = root->right;
			root->right = temp;
		}

	}
}

void print_inorder(Node* root)
{
	if(root == nullptr)
		return;
	else{
		print_inorder(root->left);
		printf("%d ", root->index);
		print_inorder(root->right);
	}
}

int main()
{
	int n,a,b;
	scanf("%d",&n);
	Node* nodes[n];
	for(int i=0;i<n;i++)
		nodes[i] = new Node(i+1);

	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&a, &b);
		if(a==-1)
			nodes[i]->left = nullptr;
		else
			nodes[i]->left = nodes[a-1];

		if(b==-1)
			nodes[i]->right = nullptr;
		else
			nodes[i]->right = nodes[b-1];
	}

	Node* root = nodes[0];

	int t,k;
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&k);
		swap(root, k, 1);
		print_inorder(root);
		printf("\n");
	}
}