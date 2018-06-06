#include <bits/stdc++.h>
#define lli long long int
#define vi vector<lli>
using namespace std;

class Graph{
private:
	int V;
	vi *list;
	vi *weights;
public:
	Graph(int v)
	{
		V = v;
		list = new vi[V];
		weights = new vi[V];
	}
	void addedge(lli a, lli b, lli w)
	{
		// printf("%d %d %d\n", a+1, b+1, w);
		list[a].push_back(b);
		weights[a].push_back(w);
	}
	lli prims(lli src)
	{
		set< pair<lli,lli> > setds;
		vector<lli> value(V, INT_MAX);
		vector<bool> done(V, false);
		setds.insert(make_pair(0, src));
		value[src]=0;

		while(!setds.empty())
		{
			lli u;
			// do
			// {
				pair<lli, lli> temp = *(setds.begin());
				setds.erase(setds.begin());
				u = temp.second;
			// }while(done[u]);

			done[u] = true;
			for(lli i=0; i<list[u].size(); i++)
			{
				lli v = list[u][i];
				lli w = weights[u][i];

				if(!done[v] && value[v] > w)
				{
					set< pair<lli,lli> >::iterator it = setds.find(make_pair(value[v], v));
					if(it != setds.end())
						setds.erase(it);

					value[v] = w;
					setds.insert(make_pair(value[v], v));
				}
			}
		}
		lli ans = 0;
		for(lli i=0;i<V;i++)
		{
			// printf("(%d %d), ",i+1, value[i]);
			ans += value[i];
		}
		return ans;
	}
	void print()
	{
		for(int i=0;i<V;i++)
		{
			printf("%d: ", i+1);
			for(int j=0; j<list[i].size(); j++)
				printf("(%d %d), ", list[i][j]+1, weights[i][j]);
			printf("\n");
		}
	}
};

int main()
{
	lli n,t,nbrs,v,w;
	char name[10];
	for(scanf("%lld",&t);t--;)
	{
		scanf("%lld", &n);
		Graph g = Graph(n);
		for(int i=0; i<n;i++)
		{
			scanf("%s", name);
			scanf("%lld", &nbrs);
			for(int j=0;j<nbrs;j++)
			{
				scanf("%lld %lld", &v, &w);
				v--;
				if(v!=i)
					g.addedge(i, v, w);
			}
		}
		// g.print();
		printf("%lld\n", g.prims(0));
	}
}

