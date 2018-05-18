#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
/** Structure Decleration **/
struct node{
    int x;
    struct node* left;
    struct node* right;
};
node* start;

/** Function to create a new node with value x and return the node **/
node* newnode(int x){
    node* temp = new node;
    temp->left=NULL;
    temp->right=NULL;
    temp->x=x;

    return temp;
}

/** Function to insert element x at a node hc **/
node* insert(node* hc,int x)
{
    if(hc==NULL)
        return newnode(x);
    else if(hc->x<=x)
        hc->right = insert(hc->right,x);
    else
        hc->left = insert(hc->left,x);

    return hc;
}

/** Function to print inorder traversal **/
void inorder(node* hc){
    if(hc!=NULL)
    {
        inorder(hc->left);
        cout<<hc->x<<" ";
        inorder(hc->right);
    }
}

/** Function to find minimum beyound a node including that node **/
node* minimum(node* hc)
{
    while(hc->left!=NULL)
    {
        hc=hc->left;
    }
    return hc;
}


/** delete function to delte a value x**/
node* del(node* hc, int x)
{
        if(hc==NULL)
        {
            cout<<"Value not found"<<endl;
            return NULL;
        }
        else if(hc->x<x)
            hc->right=del(hc->right,x);
        else if(hc->x>x)
            hc->left=del(hc->left,x);
        else
        {
            if(hc->left==NULL)
            {
                node* temp = hc->right;
                free(hc);
                return temp;
            }
            else if(hc->right==NULL)
            {
                node* temp = hc->left;
                free(hc);
                return temp;
            }
            else
            {
                struct node* temp = minimum(hc->right);
                hc->x=temp->x;
                hc->right=del(hc->right,temp->x);
            }
        }
        return hc;
}
int main()
{
    int x,n;
    start = NULL;
    while(1)
    {
        cout<<"\n1.Insert\n2.Inorder\n3.Delete\n4.Exit\n";
        cin>>x;
        switch(x){
            case 1:cout<<"Enter the number to be inserted:";
                   cin>>n;
                   start=insert(start,n);
                   break;
            case 2:inorder(start);
                   break;
            case 3:cout<<"Enter the number to be deleted:";
                   cin>>n;
                   start=del(start,n);
                   break;
            case 4:return 1;
        }
    }

}
