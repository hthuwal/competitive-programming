#include <bits/stdc++.h>
#define lli long long int
using namespace std;

class Graph
{
private:
	int v;
	vector<int> *list;
public:
	Graph(int v)
	{
		this->v=v;
		list = new vector<int> [v];
	}
	void addEdge(int a,int b)
	{
		list[a].push_back(b);
	}
	int similarPair(int x,int k)
	{
		int count = 0;
		stack<int> st;
		vector<bool> visited(v,false);
		st.push(x);
		while(!st.empty())
		{
			int top = st.top();
			st.pop();
			visited[top]=true;
			for(int i=0;i<list[top].size();i++)
			{
				if(abs(top-list[top][i])<=k)
					count++;
				if(visited[list[top][i]]==false)
				{
					st.push(list[top][i]);
				}
			}
		}
		return count;
	}
};
int main()
{
	freopen("in.txt","r",stdin);
	lli n,k;
	cin>>n>>k;
	Graph g(n);
	lli root=n*(n+1);
	root/=2;
	for(int i=0;i<n-1;i++)
	{
		lli a,b;
		cin>>a>>b;
		root-=b;
		g.addEdge(--a,--b);
	}
	
	cout<<g.similarPair(--root,k);
}