#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int a[190][190];
int x,y;
void bfs(int i,int j)
{
    int m,n,d;
    queue<int>q;
    q.push(i);
    q.push(j);
    a[i][j]=0;
    while(!q.empty())
    {
        m=q.front();
        q.pop();
        n=q.front();
        q.pop();
        d=1+a[m][n];
        if(n > 0 && d < a[m][n-1])
        {
            q.push(m);
            q.push(n-1);
            a[m][n-1] = d;
        }
        if(n < y-1 && d < a[m][n+1])
        {
            q.push(m);
            q.push(n+1);
            a[m][n+1] = d;
        }
        if(m < x-1 && d < a[m+1][n])
        {
            q.push(m+1);
            q.push(n);
            a[m+1][n] = d;
        }
        if(m > 0 && d < a[m-1][n])
        {
            q.push(m-1);
            q.push(n);
            a[m-1][n] = d;
        }
    }
}
int main()
{
    int t;
    char c;
    cin>>t;
    while(t--)
    {
        cin>>x >>y;
        vector<pair <int,int> >h;
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<y;j++)
            {
                cin>>c;
                if(c=='1')
                {
                    a[i][j]= -1000;
                    h.push_back(make_pair(i,j));
                }
                else
                {
                    a[i][j]=1000;
                }
            }
        }
    for(int i=0;i<h.size();i++)
    {
        bfs(h[i].first,h[i].second);
    }
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
    }
    return 0;
}
