#include <cstdio>
#include <queue>
using namespace std;
// int q[111111111];

typedef struct node{
    int value;
    int id;
    node* left;
    node* right;
    node* parent;
} node;
bool hchash[22222];
char spoj[111111111];

node* head;
node* makenode(int a,int id)
{
    node* temp = new node;
    temp->value=a;
    temp->id=id;
    temp->left=NULL;
    temp->right=NULL;
    temp->parent=NULL;
    return temp;
}
int hct(int n)
{
    int top;
    queue<node*> q;
    node* curr,*ans;
    head = makenode(1,1);
    q.push(head);
    while(1)
    {
        curr = q.front();q.pop();
        top = curr->value % n;
        if(top%n==0)
        {
            ans=curr;
            break;
        }
        else if(!hchash[top%n])
        {
            hchash[top%n]=true;
            curr->left = makenode((top*10)%n,0);
            curr->right = makenode(((top*10)%n+1)%n,1);
            curr->left->parent=curr;
            curr->right->parent=curr;
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    int ptr=0;
    while(ans!=NULL)
    {
        spoj[ptr++]='0'+ans->id;
        ans=ans->parent;
    }
    ptr--;
    for(int i=ptr;i>=0;i--)
        printf("%c",spoj[i]);
    printf("\n");
   
}

int main(){
    freopen("in.txt","r",stdin);
    int t,x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&x);
        for(int i=0;i<x;i++)
            hchash[i]=false;
        hct(x);
    }

}
