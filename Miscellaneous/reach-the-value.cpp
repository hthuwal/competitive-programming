/**
 * You are given 3 numbers X,A and B
 * You have to start from 0 and reach X	
 * Rules :
 * 	1. Increment/decrement your current number by 1. (This takes cost A)
 *  2. Double your current number. (This takes cost B)
 * 
 * Give the minimum cost to do so. 
 */

#include<bits/stdc++.h>

#define pii pair<int, int>
#define vpi vector<pii>
#define mp(i,j) make_pair(i, j)
#define INF INT_MAX

using namespace std;

int x,a,b,c;
int dijsktra()
{
	set<pii> heap;
	vector<int> dist(2*x+1, INF);
	heap.insert(mp(0, 0));
	dist[0] = 0;
	
	while(!heap.empty())
	{
		auto top = *heap.begin();
		heap.erase(heap.begin());

		if(top.second == x)
			return top.first;

		int u = top.second;

		vpi nbrs;

		// can do decrement only if greater than 0
		if(top.second > 0) 
			nbrs.push_back(mp(top.second-1, a));

		// can increment only if less than the target
		if(top.second < x)
			nbrs.push_back(mp(top.second+1, a));

		// can double only if less than the target and greater than 0
		if(top.second > 0 and top.second < x)
			nbrs.push_back(mp(top.second*2, b));

		for(auto nbr: nbrs)
		{
			int v = nbr.first;
			int e = nbr.second;

			if(dist[v] > dist[u] + e)
			{
				if(dist[v] != INF)
					heap.erase(heap.find(mp(dist[v], v)));

				dist[v] = dist[u] + e;
				heap.insert(mp(dist[v], v));
			}
		}
	}
	return dist[x];
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>x>>a>>b;
	cout<<dijsktra();
}