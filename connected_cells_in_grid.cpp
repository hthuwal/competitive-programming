#include <bits/stdc++.h>
using namespace std;

#define vii vector<vector<int> >

int dfs(vii &grid, int i, int j)
{
	if(i<0 || i >=grid.size() || j <0 || j>= grid[0].size() || grid[i][j] != 1)
		return 0;
	else
	{
		grid[i][j] = -1;
		return 1 + dfs(grid, i, j+1) + dfs(grid, i, j-1) 
		+ dfs(grid, i-1, j-1) + dfs(grid, i-1, j) + dfs(grid, i-1, j+1) 
		+ dfs(grid, i+1, j-1) + dfs(grid, i+1, j) + dfs(grid, i+1, j+1);
	}
}

int maxRegion(vii &grid)
{
	int n = grid.size();
	int m = grid[0].size();
	int ans = 0, temp;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(grid[i][j] == 1)
			{
				temp = dfs(grid, i, j);
				if(temp > ans)
					ans = temp;
			}
		}
	}
	return ans;	
}
int main()
{

}