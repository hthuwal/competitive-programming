#include<iostream>
using namespace std;
int main()
{
    int n,count,a,t,i;
    cin>>n;
    int hc[10005]={0};
    while(n--)
    {
        cin>>a;
        hc[a]=1;
        cin>>t;
        while(t--)
        {
            cin>>a;
            if(hc[a]!=1)
            {
                hc[a]=-1;
            }
        }
    }
    for(i=0,count=0;i<10005;i++)
    {
        if(hc[i]==-1)
            count++;
    }
    cout<<count<<endl;
}
