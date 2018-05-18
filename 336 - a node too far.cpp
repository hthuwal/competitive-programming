/*input
16
10 15 15 20 20 25 10 30 30 47 47 50 25 45 45 65
15 35 35 55 20 40 50 55 35 40 55 60 40 60 60 65
35 2 35 3 0 0
14
1 2 2 7 1 3 3 4 3 5 5 10 5 11
4 6 7 6 7 8 7 9 8 9 8 6 6 11
1 1 1 2 3 2 3 3 0 0
0
*/
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cstdio>
#define vi vector<int>
using namespace std;
class Graph{
private:
	int v;
	vi *list;
public:
	Graph(int v=35)
	{
		this->v=v;
		list = new vi[v];
	}
	void clear()
	{
		for(int i=0;i<v;i++)
			list[i].clear();
	}
	void addEdge(int a,int b)
	{
		list[a].push_back(b);
		list[b].push_back(a);
	}
	int bfs(int s,int ttl)
	{
		int count=0;
		vector<bool> visited (v,false);
		queue<pair<int,int> > q;
		q.push(make_pair(s,ttl));
		count++;
		// cout<<s<<" ";
		visited[s]=true;
		while(!q.empty())
		{
			pair<int,int> f = q.front();
			q.pop();
			int front = f.first;
			int nttl = f.second-1;
			if(nttl>=0)
			{
				for(int i=0;i<list[front].size();i++)
				{
					if(!visited[list[front][i]])
					{
						visited[list[front][i]]=true;
						count++;
						// cout<<list[front][i]<<" ";
						q.push(make_pair(list[front][i],nttl));
					}
				}
			}
		}
		return count;
	}
};
int main()
{
	freopen("in.txt","r",stdin);
	Graph g;
	int t = 1;
	while(1)
	{
		g.clear();
		int l=0;
		map<int,int> hc;
		int n,a,b;
		cin>>n;
		if(n==0) break;
		for(int i=0;i<n;i++)
		{
			cin>>a>>b;
			if(hc.find(a)==hc.end())
			{
				hc[a]=l; l++;
			}
			if(hc.find(b)==hc.end())
			{
				hc[b]=l;l++;
			}
			g.addEdge(hc[a],hc[b]);
		}
		while(1)
		{
			cin>>a>>b;
			if(a==0 && b==0)
				break;
			else
			{
				int x = g.bfs(hc[a],b);
				x = hc.size()-x;
				cout<<"Case "<<t<<": "<<x<<" nodes not reachable from node "<<a<<" with TTL = "<<b<<".\n";
			}
			t++;
		}
	}
}