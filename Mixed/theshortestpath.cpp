#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
#include<map>
#include<queue>
#include<cstdio>
using namespace std;
struct vertex{
	int b;
	int x;
};
map<string,int> mymap;
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
	int t,v,k,hc,a,b,x,i,j,p,q,y;
	vertex temp
;	string name,aadi,jp;
	cin>>t;
	while(t--)
	{
		/**input**/
		cin>>v;
		for(i=0;i<11000;i++)
			graph[i].clear();
		mymap.clear();
		for(i=1;i<=v;i++)
		{
			cin>>name;
			mymap[name]=i;
			scanf("%d",&k);
			for(j=0;j<k;j++)
			{
				scanf("%d %d",&b,&x);
				temp.b=b;
				temp.x=x;
				graph[i].push_back(temp);
				temp.b=i;
				graph[b].push_back(temp);
			}
		}
		/** distances to be calculated **/
		scanf("%d",&x);
		while(x--)
		{
			for(i=0;i<=v;i++)
			{
				inset[i]=0;
				dist[i]=INT_MAX;
				//cout<<dist[i]<<endl;
			}
			cin>>aadi>>jp;
			a=mymap[aadi];
			b=mymap[jp];
			dist[a]=0;
			/*dijkstra**/
			while(1)
			{
				hc=find(v);
				if(hc==-1)
					break;
				inset[hc]=1;
				for(i=0;i<graph[hc].size();i++)
				{
					p = hc;
					q = graph[hc][i].b;
					y = graph[hc][i].x;
					dist[q]=(dist[p]+y<dist[q]?dist[p]+y:dist[q]);
				}
			}
			dist[b]==INT_MAX?printf("NO\n"):printf("%d\n",dist[b]);
		}
		dist[a]=0;
		
	}
}