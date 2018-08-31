#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
using namespace std;
struct vertex{
	int b;
	int x;
};

vector<vertex>graph[11000];
int inset[11000];
int dist[11000];
int find(int v)
{
	int i,k,min;
	for(i=1,min=INT_MAX,k=-1;i<=v;i++)
	{
		if(!inset[i] && dist[i]<min)
		{
			min=dist[i];
			k=i;
		}
	}
	return k;
}
int main()
{
	int t,v,k,hc,a,b,x,i;
	cin>>t;
	while(t--)
	{
		cin>>v>>k;
		for(i=0;i<11000;i++)
			graph[i].clear();
		for(i=0;i<=v;i++)
		{
			inset[i]=0;
			dist[i]=INT_MAX;
			//cout<<dist[i]<<endl;
		}
		for(i=0;i<k;i++)
		{
			cin>>a>>b>>x;
			vertex temp;	
			temp.b=b;
			temp.x=x;
			graph[a].push_back(temp);
		}
		cin>>a>>b;
		dist[a]=0;
		while(1)
		{
			hc=find(v);
			if(hc==-1)
				break;
			inset[hc]=1;
			for(i=0;i<graph[hc].size();i++)
			{
				int p = hc;
				int q = graph[hc][i].b;
				int y = graph[hc][i].x;
				dist[q]=(dist[p]+y<dist[q]?dist[p]+y:dist[q]);
			}
		}
		dist[b]==INT_MAX?cout<<"NO\n":cout<<dist[b]<<endl;
	}
}