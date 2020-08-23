#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

class edge{
	public:
	long long int x;
	long long int y;
	long long int w;
	edge(long long int x,long long int y,long long int w)
	{
		this->x=x;
		this->y=y;
		this->w=w;
	}
};
class Graph{
public:
	vector<edge> edgelist;
};
bool comp(edge a,edge b)
{
	return a.w>b.w;
}
/**
 * @param
 * @param
 * @return
 */
long long int find(long long int parent[],long long int n)
{
	if(parent[n]==-1)
		return n;
	else
		return find(parent,parent[n]);
}
void uniont(long long int x,long long int y,long long int parent[])
{
	x = find(parent,x);
	y = find(parent,y);
	parent[x]=y;
}
bool iscycle(Graph mst)
{
	long long int parent[1100];
	memset(parent,-1,sizeof(parent));
	for(long long int i=0;i<mst.edgelist.size();i++)
	{
		long long int x = find(parent,mst.edgelist[i].x);
		long long int y = find(parent,mst.edgelist[i].y);
		if(x==y)
			return true;
		else
			uniont(x,y,parent);
	}
	return false;
}
int main()
{
	long long int p,t,n,m,a,b,c,i;
	cin>>t;
	while(t--)
	{
		
		cin>>p>>n>>m;
		Graph hc;
		Graph mst;
		for(i=0;i<m;i++)
		{
			cin>>a>>b>>c;
			edge temp(a,b,c);
			hc.edgelist.push_back(temp);
		}
		sort(hc.edgelist.begin(),hc.edgelist.end(),comp);
		while(mst.edgelist.size()!=n-1)
		{
			edge back = hc.edgelist.back();
			hc.edgelist.pop_back();
			mst.edgelist.push_back(back);
			if(iscycle(mst))
				mst.edgelist.pop_back();
		}
		long long int ans=0;
		for(i=0;i<n-1;i++)
		{
			ans+=mst.edgelist[i].w;
		}
		ans = ans*p;
		cout<<ans<<endl;
	}
}
