#include<bits/stdc++.h>

using namespace std;

// Using Class to represent a node
class Node{
public:
	string value;
	Node* next;
	Node(string v, Node *next)
	{
		this->value = v;
		this->next=next;
	}
};

// Using Struct
struct Noddy
{
	string value;
	Noddy* next;
};

int main()
{
	Node *a3 = new Node("Thuwal", NULL);
	Node *a2 = new Node("Chandra", a3);
	Node *a1 = new Node("Harish", a2);

	Node* head = a1;
	while(head!=NULL)
	{
		cout<<head->value<<" ";
		head = head->next;
	}
	cout<<"\n";

	Noddy *b3 = new Noddy{"Thuwal", NULL};
	Noddy *b2 = new Noddy{"Chandra", b3};
	Noddy *b1 = new Noddy{"Harish", b2};

	Noddy* bhead = b1;
	while(bhead!=NULL)
	{
		cout<<bhead->value<<" ";
		bhead = bhead->next;
	}
	cout<<"\n";
}
