#include <iostream>
using namespace std;

typedef struct node{
    int t;
    struct node* left;
    struct node* right;
}node;

class bst{
public:
    node *root;
public:
    bst()
    {
        root=NULL;
    }
    void addnode(int t)
    {
        node *x = new node;
        x->t=t;
        x->left=NULL;
        x->right=NULL;
        if(root==NULL)
            root=x;
        else
        {
            node *temp =root;
            while(1)
            {
                if(temp->t<t)
                {
                    if(temp->right==NULL)
                    {
                        temp->right=x;
                        break;
                    }
                    else{
                        temp=temp->right;
                    }
                }
                else
                {
                    if(temp->left==NULL)
                    {
                        temp->left=x;
                        break;
                    }
                    else{
                        temp=temp->left;   
                    }
                }
            }
        }
    }
};
node *lca(int n1,int n2,node* root)
{
        
    if(root->t>n1 && root->t>n2)
        return lca(n1,n2,root->left);
    else if(root->t<n1 && root->t<n2)
        return lca(n1,n2,root->right);
    else
        return root;
}
int ans(int n,node* root)
{
    int hc = root->t;
    while(1)
    {
        if(root->t>hc)
            hc=root->t;
        if(root->t==n)
            break;
        else if(root->t>n)
            root=root->left;
        else
            root=root->right;
    }
    return hc;
}
int main()
{
    int n;
    cin>>n;
    bst b;
    
    for(int i=0,j;i<n;i++)
    {
        cin>>j;
        b.addnode(j);
    }
    int x,y;
    cin>>x>>y;
    if(x>y)
    {
        int temp = y;
        y=x;
        x=temp;
    }
    cout<<ans(y,lca(x,y,b.root));
}
