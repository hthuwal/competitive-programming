//precomputation with recursive approach then direct recursive approach //
#include<iostream>
#include<cstring>
int array[2000000];
using namespace std;

int check(int x,int l, int k){
    if(x<=0)
        return 0;
    else if(array[x]==1)
        return 1;
    else if(array[x]==-1)
        return -1;
    else if(array[x]==0)
    {
        if(check(x-1,k,l)==-1 || check(x-l,k,l)==-1 || check(x-k,k,l)==-1)
        {
            array[x]=1;
            return 1;
        }
        else
        {
            array[x]=-1;
            return -1;
        }
    }

}
int main()
{
    int k,l,m,n,i;
    memset(array,0,2000000);
    cin>>k>>l>>m;
    array[1]=array[k]=array[l]=1;
    for(i=1;i<1100000;i++){
        if(array[i]==0)
            check(i,k,l);
    }
    while(m--){
        cin>>n;
        if(array[n]==1)
            cout<<'A';
        else
            cout<<'B';
    }
}
