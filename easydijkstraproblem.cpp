#include<iostream>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
struct vertex{
	int x;
	int weight;
};
vector<vertex>list[20000];
set<int>spt;
set<int>ingraph;
int dist[20000];
int selectmin(int n)
{
	int i,k,min;
	for(i=1,k=-1,min=1000000000;i<=n;i++)
	{
		if(ingraph.count(i)>0 && spt.count(i)==0 && dist[i]<min && dist[i]!=200000000)
		{
			k=i;
			min=dist[i];
		}
	}
	return k;
}
int main()
{
	int t,a,b,c,v,k,i;
	cin>>t;
	while(t--)
	{
		for(i=0;i<20000;i++)
		{
			dist[i]=200000000;
			list[i].clear();
		}
		spt.clear();
		ingraph.clear();
		
		cin>>v>>k;
		while(k--)
		{
			cin>>a>>b>>c;
			vertex temp;
			temp.x=b;
			temp.weight=c;
			list[a].push_back(temp);
			ingraph.insert(a);
			ingraph.insert(b);
		}
		cin>>a>>b;
		dist[a]=0;
		while(spt.size()<v)
		{
			k=selectmin(v);
			if(k==b || k==-1)
			{
				break;
			}
			spt.insert(k);
			for(i=0;i<list[k].size();i++)
			{
				if(spt.count(list[k][i].x)==0 && dist[list[k][i].x] > dist[k]+list[k][i].weight)
					dist[list[k][i].x]=dist[k]+list[k][i].weight;
			}
		}
		if(k==-1)
			cout<<"No"<<endl;
		else
			cout<<dist[k]<<endl;
	}
	return 0;
}