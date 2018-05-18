#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;
int graph[150][150];
int dist[150][150];
void apsp(int v)
{
	for(int k=0;k<v;k++)
	{
		for(int i=0;i<v;i++)
		{
			for(int j=0;j<v;j++)
			{
				if(dist[i][k]!=INT_MAX && 
				   dist[k][j]!=INT_MAX && 
				   dist[i][k]+dist[k][j]<dist[i][j])
				{
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
	#endif

    for(int i=0;i<150;i++)
    {
    	for(int j=0;j<150;j++)
    	{
    		if(i==j)
    		{
    			graph[i][j]=0;
    			dist[i][j]=0;	
    		}
    		else
    		{
	    		graph[i][j]=INT_MAX;
	    		dist[i][j]=INT_MAX;
	    	}
    	}
    }
    int v,e,a,b,c;
    cin>>v;
    cin>>e;
    for(int i=0;i<e;i++)
    {
    	cin>>a>>b>>c;
    	graph[a][b]=c;
    	dist[a][b]=c;
    }
    apsp(v);
    for(int i=0;i<v;i++)
    {
    	for(int j=0;j<v;j++)
    	{
    		if(dist[i][j]==INT_MAX)
    			cout<<"INF"<<" ";
    		else
    			cout<<dist[i][j]<<" ";
    	}
    	cout<<endl;
    }
}