#include <iostream>
#include <cstdio>
using namespace std;
int a[1100][1100];
int hc(int j,int n)
{
    int ans=1;
    int current=1;
    int aadi=a[0][j];
    for(int i=1;i<n;i++)
    {
        
        if(a[i][j]==aadi)
            current++;
        else 
        {
            if(current>ans)
                ans=current;
            current=1;
            aadi=a[i][j];
        }

        if(i==n-1)
        {
            if(current>ans)
                ans=current;
            current=1;
            aadi=a[i][j];
        }
    }
    return ans;
}
int aditi(int j,int n)
{
    int ans=1;
    int current=1;
    int aadi=a[j][0];
    for(int i=1;i<n;i++)
    {
        
        if(a[j][i]==aadi)
            current++;
        else 
        {
            if(current>ans)
                ans=current;
            current=1;
            aadi=a[j][i];
        }

        if(i==n-1)
        {
            if(current>ans)
                ans=current;
            current=1;
            aadi=a[j][i];
        }
    }
    return ans;
}

int main()
{
    freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>a[i][j];
        int p=1,q=1;
        for(int i=0;i<n;i++)
        {
            int x=aditi(i,m);
            if(x>p)
                p=x;
        }

        for(int i=0;i<m;i++)
        {
            int x=hc(i,n);
            if(x>q)
                q=x;
        }
        cout<<p*q<<endl;
    }
}