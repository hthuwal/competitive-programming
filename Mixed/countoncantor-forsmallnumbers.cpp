#include<iostream>
using namespace std;
#define x 10000000
int hc[x];
int jp[x];
int main()
{
    int t,n,i,j,p;
    hc[1]=1;
    n=2;
    p=3;
    while(n<x)
    {
        for(i=1;i<=p;i++,n++)
        {
            hc[n]=i;
        }
        for(i=p-1;i>=1;i--,n++)
        {
            hc[n]=i;
        }
        p=p+2;
    }
    n=1;
    p=2;
    while(n<x)
    {
        for(i=1;i<=p;i++,n++)
        {
            jp[n]=i;
        }
        for(i=p-1;i>=1;i--,n++)
        {
            jp[n]=i;
        }
        p=p+2;
    }
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout <<"TERM "<<n<<"IS "<<hc[n]<<"/"<<jp[n]<<endl;
    }
}
