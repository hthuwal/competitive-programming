#include<iostream>
#include<stack>
using namespace std;
struct node{
    char x;
    struct node* left;
    struct node* right;
};
int operation(int a,int b,char c)
{
    switch(c){
        case '+':return a+b;
        case '-':return a-b;
        case '*':return a*b;
        case '/':return a/b;
    }
}
void inorder(node *hc)
{
    if(hc!=NULL)
    {
        if(hc->x=='+' || hc->x=='-' || hc->x=='*' || hc->x=='/')
        cout<<"(";
        inorder(hc->left);
        cout<<hc->x;
        inorder(hc->right);
        if(hc->x=='+' || hc->x=='-' || hc->x=='*' || hc->x=='/')
        cout<<")";
    }
}
int evaluate(node* hc){

    if(hc!=NULL)
    {
        if(hc->x=='+' || hc->x=='-' || hc->x=='*' || hc->x=='/')
        {
            return operation(evaluate(hc->left),evaluate(hc->right),hc->x);
        }
        else
        {
            return (hc->x-'0');
        }
    }
}
int main()
{
    stack<node*>hc;
    string a;
    cin>>a;
    node* j=new node;
    for(int i=0;i<a.length();i++)
    {
        if(a[i]!='+' && a[i]!='-' && a[i]!='*' && a[i]!='/')
        {
            node* temp = new node;
            temp->x=a[i];
            temp->left=NULL;
            temp->right=NULL;
            hc.push(temp);
        }
        else
        {
            node *temp = new node;
            temp->x=a[i];
            node *temp2 = hc.top();
            hc.pop();
            node *temp3=hc.top();
            hc.pop();
            temp->right=temp2;
            temp->left=temp3;
            hc.push(temp);
        }
    }
    node *temp = hc.top();
    inorder(temp);
    cout<<endl<<evaluate(temp);
}
