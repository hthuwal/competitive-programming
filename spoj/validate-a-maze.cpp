/**
 * https://www.spoj.com/problems/MAKEMAZE/
 */

#include<bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define vpi vector<pi> 
int t,n,m;
int x[] = {-1, 0, 1 , 0};
int y[] = {0, -1, 0, 1};
char maze[21][21];
bool vis[21][21];

bool is_reachable(pi s, pi d)
{
	queue<pi> q;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			vis[i][j]=false;

	q.push(s);
	vis[s.first][s.second] = true;
	while(!q.empty())
	{	
		auto top = q.front(); q.pop();
		for(int i=0;i<4;i++)
		{
			int nbrx = top.first + x[i];
			int nbry = top.second + y[i];

			if(nbrx >= 0 and nbrx <= n-1 and nbry >= 0 and nbry <= m-1)
			{
				if(nbrx == d.first and nbry == d.second)
					return true;
				if(maze[nbrx][nbry] == '.' and not vis[nbrx][nbry])
				{
					vis[nbrx][nbry] = true; 
					q.push({nbrx, nbry});
				}
			}
		}
	}
	return false;
}

int main()
{
	cin.sync_with_stdio(false);
	
	cin>>t;

	while(t--)
	{
		cin>>n>>m;
		vpi openings;

		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				bool isedge = i == 0 || i == n-1 || j==0 || j==m-1;
				cin>>maze[i][j];
				if(isedge and maze[i][j] == '.')
					openings.push_back({i, j});
			}

		if(openings.size() == 2)
		{
			if(is_reachable(openings[0], openings[1]))
				cout<<"valid\n";
			else
				cout<<"invalid\n";
		}
		else
			cout<<"invalid\n";
	}
}