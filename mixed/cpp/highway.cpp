#include <cstdio>
#include <vector>
#include <set>
#include <climits>

#define INF INT_MAX
using namespace std;

class Graph{
	int V;
	vector<pair<int,int> > *list;
public:
	Graph(int v)
	{
		this->V = v;
		list = new vector< pair<int,int> >[v];
	}
	void addedge(int a,int b, int c)
	{
		list[a].push_back(make_pair(b, c));
		list[b].push_back(make_pair(a, c));
	}
	int dijsktra(int s, int d)
	{
		set<pair<int,int> > st;
		st.insert(make_pair(0, s));

		vector<int> dist(V,INF);
		dist[s]=0;

		while(!st.empty())
		{
			pair<int, int> temp = *(st.begin());
			int u = temp.second;
			st.erase(st.begin());

			for(int i=0;i<list[u].size();i++)
			{
				int v = list[u][i].first;
				int w = list[u][i].second;

				if(dist[u]+w < dist[v])
				{
					if(dist[v]!=INF)
                		st.erase(st.find(make_pair(dist[v],v)));
					
					
	                dist[v]=dist[u]+w;
	                st.insert(make_pair(dist[v],v));
				}
			}
		}
		return dist[d];
	}
};

int main()
{
	int t,v,e,s,d,x,y,z;
	for(scanf("%d",&t);t--;)
	{
		scanf("%d %d %d %d",&v,&e,&s,&d);
		Graph g(v);
		for(int i=0;i<e;i++)
		{
			scanf("%d %d %d",&x,&y,&z);
			g.addedge(--x,--y,z);
			g.addedge(y,x,z);
		}
		int ans = g.dijsktra(--s,--d);
		if(ans==INF)
			printf("NONE\n");
		else
			printf("%d\n",ans);
	}
}