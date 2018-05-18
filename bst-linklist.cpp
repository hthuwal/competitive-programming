#include<iostream>
using namespace std;
struct node{
    int x;
    struct node* left;
    struct node* right;
};
struct node* start;
void insert(int n){
    node* hc = new node;
    hc->left=NULL;
    hc->right=NULL;
    hc->x=n;
    if(start==NULL)
        start=hc;
    else{
        node* temp=start;
        while(1){
            if(temp->x < n)
            {
                if(temp->right==NULL){
                    temp->right=hc;
                    break;
                }
                else
                    temp=temp->right;
            }
            else
            {
                if(temp->left==NULL){
                    temp->left=hc;
                    break;
                }
                else
                    temp=temp->left;
            }
        }
    }
}
void inorder(node* hc){
    if(hc!=NULL){
        inorder(hc->left);
        cout<<hc->x<<" ";
        inorder(hc->right);
    }
}

void search(int x)
{
    node* temp = start;
    if(temp==NULL)
}
int main()
{
    int x,n;
    start = NULL;
    while(1)
    {
        cout<<"\n1.Insert\n2.Inorder\n3.Exit\n";
        cin>>x;
        switch(x){
            case 1:cout<<"Enter the number to be inserted:";
                   cin>>n;
                   insert(n);
                   break;
            case 2:inorder(start);
                   break;
            case 3:return 1;
        }

    }

}
