#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph{
private:
	int v;
	vector<int> *list;
public:
	Graph(int v)
	{
		this->v=v;
		list = new vector<int> [v];
	}
	void addedge(int a,int b)
	{
		list[a].push_back(b);
		list[b].push_back(a);
	}
	void dfs(int src)
	{
		vector<bool> visited (v,false);
		stack<int> st;
		st.push(src);
		while(!st.empty())
		{
			int top = st.top();
			st.pop();
			if(!visited[top])
			{
				visited[top]=true;
				cout<<top<<" ";
				for(int i=0;i<list[top].size();i++)
				{
					if(!visited[list[top][i]])
					{
						st.push(list[top][i]);
					}
				}
			}
		}
	}
};
int main()
{
	Graph g(6);
	g.addedge(0,1);
	g.addedge(0,2);
	g.addedge(1,3);
	g.addedge(2,3);
	g.addedge(2,4);
	g.addedge(3,5);
	g.dfs(0);
}