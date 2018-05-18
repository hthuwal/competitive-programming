/*input
5
5
0 1 1 1 1
1 0 0 0 1
1 1 0 1 0
0 1 0 1 1
0 1 1 1 0
*/
#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;
class graph{
private:
	int V;
	vector<int> *list;
	vector<int> visited;
	vector<int> val;
public:
	graph(int x)
	{
		V=x;
		list = new vector<int> [x];
		visited.assign(V,0);
		val.assign(V,0);
	}
	void addedge(int a,int b)
	{
		list[a].push_back(b);
		list[b].push_back(a);
	}
	void setval(int i)
	{
		val[i]=1;
	}
	int dfs(int s)
	{
		int count = 0;
		stack<int> st;
		st.push(s);
		while(!st.empty())
		{
			int top = st.top();
			st.pop();
			if(visited[top]==0)
			{
				visited[top]=1;
				// cout<<top<<" ";
				count++;
				for(int i=0;i<list[top].size();i++)
				{
					if(visited[list[top][i]]==0)
					{
						st.push(list[top][i]);
					}
				}
			}
		}
		return count;
	}
	int ans()
	{
		int max=0;
		for(int i=0;i<V;i++)
		{
			if(visited[i]==0 && val[i]==1)
			{
				int x = dfs(i);
				// cout<<x<<" ";
				if(x>max)
					max=x;
			}
		}
		return max;
	}

	void display()
	{
		for(int i=0;i<V;i++)
		{
			cout<<i<<": ";
			for(int j=0;j<list[i].size();j++)
				cout<<list[i][j]<<" "; 
			cout<<endl;
		}
	}
};
int getnode(int i,int j,int c)
{
	return i*c+j;
}
int main()
{
	int r,c;
	cin>>r>>c;
	graph g(r*c);
	vector<vector<int> > a(r,vector<int> (c,0));
	
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>a[i][j];
		}
	}
	
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(a[i][j]==1)
			{
				int p = getnode(i,j,c);
				g.setval(p);
				if(i>=1 && j>=1 && a[i-1][j-1]==1)
					g.addedge(p,getnode(i-1,j-1,c));
				if(i>=1 && j<c-1 && a[i-1][j+1]==1)
					g.addedge(p,getnode(i-1,j+1,c));
				if(i<r-1 && j>=1 && a[i+1][j-1]==1)
					g.addedge(p,getnode(i+1,j-1,c));
				if(i<r-1 && j<c-1 && a[i+1][j+1]==1)
					g.addedge(p,getnode(i+1,j+1,c));
				if(i>=1 && a[i-1][j]==1)
					g.addedge(p,getnode(i-1,j,c));
				if(i<r-1 && a[i+1][j]==1)
					g.addedge(p,getnode(i+1,j,c));
				if(j>=1 && a[i][j-1]==1)
					g.addedge(p,getnode(i,j-1,c));
				if(j<c-1 && a[i][j+1]==1)
					g.addedge(p,getnode(i,j+1,c));
			}
		}
	}
	// g.display();
	cout<<g.ans();
}