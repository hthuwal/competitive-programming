#include <iostream>
#include <cstring>
using namespace std;
void insert(int a[],int x){
    int i=1;
    while(a[i]!=-1){
        if(a[i]<x)
            i=2*i+1;
        else
            i=2*i;
    }
    a[i]=x;
}
void inorder(int a[],int x)
{
    if(a[x]!=-1){
        inorder(a,2*x);
        cout<<a[x]<<" ";
        inorder(a,2*x+1);
    }
}
int main()
{
    int a[10000],x,n;
    memset(a,-1,10000);
    while(1)
    {
        cout<<"\n1.Insert\n2.Inorder\n3.Exit\n";
        cin>>x;
        switch(x){
            case 1:cout<<"Enter the number to be inserted:";
                   cin>>n;
                   insert(a,n);
                   break;
            case 2:inorder(a,1);
                   break;
            case 3:return 1;
        }

    }
}
