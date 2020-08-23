/**
 * https://www.spoj.com/problems/RMQSQ/
 * Offline Query Evalutation using Union Find
 */

#include <bits/stdc++.h>
#define f(i,n) for(int i=0;i<n;i++)
#define N 100005
using namespace std;

int a[N];
int parent[N];
int size[N];

int find(int i)
{
	if(parent[i] == i)
		return i;
	return parent[i] = find(parent[i]);
}

struct query{
	int l, r, index;
};

int main()
{
	ios::sync_with_stdio(false);
	int n,q;
	cin>>n;
	
	// Take Input
	f(i,n) cin>>a[i];
	
	cin>>q;
	
	// buckets[i] will hold all the queries of form [l:i]
	vector<vector<query>> buckets(n, vector<query>());

	vector<int> answer(q,0);
	
	f(i,q) 
	{
		int l, r;
		cin>>l>>r;
		query q = {l, r, i};
		buckets[r].push_back(q);
	}

	f(i, n) parent[i]=i;
	
	// Offline query evaluation using union find
	
	// Using the first i elements: the parent of an element is the next smaller element to the right of it. 
	
	// Then using this structure the answer to a query will be the a[find_set(L)], the smallest number to the right of L.

	stack<int> s;
	f(i,n)
	{
		while(!s.empty() && a[s.top()] > a[i])
		{
			parent[s.top()] = i;
			s.pop();
		}
		s.push(i);
		
		// for each query of type [L:i]
		for(query q: buckets[i]){
			
			// answer for each query
			answer[q.index] = a[find(q.l)];
		}
	}
	for(int i=0;i<q;i++)
		cout<<answer[i]<<endl;
}