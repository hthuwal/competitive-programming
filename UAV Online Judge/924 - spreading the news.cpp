/*input

*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#define vi vector<int>
using namespace std;
class graph{
private:	
	int v;
	vi *list;
public:
	graph(int v)
	{
		this->v=v;
		list = new vi[v];
	}
	~graph()
	{
		for(int i=0;i<v;i++)
		{
			list[i].clear();
		}
		delete [] list;
	}
	void addedge(int a,int b)
	{
		list[a].push_back(b);
		// list[b].push_back(a);
	}
	void hc(int source)
	{
		vector<int>visited (v,-1);
		queue<int> q;
		int boom=0;
		int dayofboom = 0;
		q.push(source);
		visited[source]=0;
		while(!q.empty())
		{
			int front = q.front(); q.pop();
			int count=0;
			int day = visited[front]+1;
			for(int i=0;i<list[front].size();i++)
			{
				if(visited[list[front][i]]==-1)
				{
					count++;
					visited[list[front][i]]=day;
					q.push(list[front][i]);
				}
			}
		}
		vector<int>hash(v,0);
		for(int i=0;i<v;i++)
		{
			if(visited[i]!=-1)
				hash[visited[i]]++;
		}
		int max,p;
		max=-1;p=-1;
		for(int i=0;i<v;i++)
		{
			if(hash[i]>max)
			{	
				max=hash[i];
				p=i;
			}
			else if(p==0 && hash[i]==max && max==1)
			{
				p=i;
			}
		}
		if(p==0)
			cout<<0<<endl;
		else
			cout<<max<<" "<<p<<endl;
	}
	void printgraph()
	{
		for(int i=0;i<v;i++)
		{
			//cout<<list[i].size()<<" ";
			for(int j=0;j<list[i].size();j++)
			{
				cout<<list[i][j]<<" ";
			}
			cout<<endl;
		}
	}
};
int main()
{
	freopen("in.txt","r",stdin);
	int v,n,x,t;
	cin>>v;
	graph g(v);
	for(int i=0;i<v;i++)
	{
		cin>>n;
		for(int j=0;j<n;j++)
		{
			cin>>x;
			g.addedge(i,x);
		}
	}
	cin>>t;
	while(t--)
	{
		cin>>x;
		// g.hc(x);
	}
	g.printgraph();
}
