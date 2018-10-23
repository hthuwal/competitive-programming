/**
 * Since there are no potions.
 * Problem is to find the shortest path from 
 * source to destination.
 */

#include <bits/stdc++.h>
#define pii pair<int, int>
#define f(i,n) for(int i=0;i<n;i++)
using namespace std;
int grid[105][105];
int dis[105][105];
int n, m;

int dijsktra(int sr, int sc, int tr, int tc)
{
	priority_queue<pair<int, pii>> heap;
	heap.push({0, {sr, sc}});

	dis[sr][sc] = 0;
	while(!heap.empty())
	{
		pair<int, pii> top = heap.top(); heap.pop();
		int ur = top.second.first;
		int uc = top.second.second;

		if(ur == tr and uc == tc)
			return -top.first;

		vector<pair<int, int>> nbrs;

		if(ur > 0 and grid[ur-1][uc] != -100000)
			nbrs.push_back({ur-1, uc});
		if(uc > 0 and grid[ur][uc-1] != -100000)
			nbrs.push_back({ur, uc-1});
		if(ur < n-1 and grid[ur+1][uc] != -100000)
			nbrs.push_back({ur+1, uc});
		if(uc < m-1 and grid[ur][uc+1] != -100000)
			nbrs.push_back({ur, uc+1});

		for(auto nbr: nbrs)
		{
			int vr = nbr.first;
			int vc = nbr.second;
			int e = -grid[vr][vc];

			if(dis[vr][vc] > dis[ur][uc] + e)
			{
				dis[vr][vc] = dis[ur][uc] + e;
				heap.push({-dis[vr][vc], {vr, vc}});
			}
		}
	}
	return dis[tr][tc];
}
int main()
{
	int t,e,tr,tc,sr,sc;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d %d %d %d %d %d %d",&n, &m,&e,&sr, &sc, &tr, &tc);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				scanf("%d",&grid[i][j]);
				dis[i][j] = INT_MAX;
			}

		int cost = dijsktra(--sr, --sc, --tr, --tc);
		
		if(cost == INT_MAX or e < cost)
			printf("Case #%d: %d\n", i, -1);
		else
			printf("Case #%d: %d\n", i, e-cost);
	}
}