#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;
int dist[150][150];
void apsp(int v)
{
	for(int k=1;k<=v;k++)
	{
		for(int i=1;i<=v;i++)
		{
			for(int j=1;j<=v;j++)
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
    			dist[i][j]=0;	
    		}
    		else
    		{ 
	    		dist[i][j]=INT_MAX;
	    	}
    	}
    }
    int v,e,a,b,c,exit,timer;
    cin>>v>>exit>>timer;
    cin>>e;
    for(int i=0;i<e;i++)
    {
    	cin>>a>>b>>c;
    	dist[a][b]=c;
    }
    apsp(v);
    int count=0;
    for(int i=1;i<=v;i++)
    {
        if(dist[i][exit]<=timer)
            count++;
    }
    cout<<count;
    
}