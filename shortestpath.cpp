#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
struct vertex{
	int id;
	int c;
	int p;
};
int isVisited[1000];
vector <vertex>list[1000];
void dfs(int x)
{
	int top,i;
	stack<int>s;
	s.push(x);
	while(!s.empty())
	{
		top=s.top();
		s.pop();
		isVisited[x]=1;
		for(i=0;i<list[top].size();i++)
		{
			if(isVisited[list[top][i].id]==0)
			{
				s.push[list[top][j].id];
			}
		}
	}
}
int main()
{
	cin>>t;
	while(t--)
	{
		memset(isVisited,0,1000);
		cin>>n>>m>>q;
		for(i=0;i<m;i++)
		{
			cin>>a>>b>>c;
			a--;
			b--;
			vertex temp;
			temp.id=b;
			temp.c=c;
			list[a].push_back(temp);
			temp.id=a;
			list[b].push_back(temp);
		}
	}
}