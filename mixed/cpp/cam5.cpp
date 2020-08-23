#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

class Graph
{
private:
	int v;
	vector<int> *list;
public:
	Graph(int n){
		v = n;
		list = new vector<int>[n];
	}
	void add_edge(int a, int b)
	{
		list[a].push_back(b);
		list[b].push_back(a);
	}
	void dfs(int source, vector<bool> &visited)
	{
		if(visited[source])
			return;

		stack<int> st;
		st.push(source);
		while(!st.empty())
		{
			int top = st.top(); st.pop();
			visited[top] = true;
			for(int i=0;i<list[top].size();i++)
			{
				if(!visited[list[top][i]])
				{
					st.push(list[top][i]);
				}
			}
		}
	}

	int num_connected_components()
	{
		vector<bool> visited(v, false);
		int ans = 0;
		for(int i=0;i<v;i++)
		{
			if(!visited[i])
			{
				ans++;
				dfs(i, visited);
			}
		}
		return ans;
	}
};
int main()
{
	Graph g(4);
	int t,n,a,b,e;
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);
		Graph g(n);
		scanf("%d",&e);
		for(int i=0;i<e;i++)
		{
			scanf("%d %d",&a,&b);
			g.add_edge(a,b);
		}
		printf("%d\n", g.num_connected_components());
	}
}