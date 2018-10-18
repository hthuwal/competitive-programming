/**
 * https://www.spoj.com/problems/RMQSQ/
 * Online Query Evaluation Using Sparse Table
 * - Updates Not Supported
 */

#include <bits/stdc++.h>
#define f(i,n) for(int i=0;i<n;i++)
#define N 100005
#define log2N 18
using namespace std;

int a[N];
int minimum[N][log2N];

void preprocessing(int n)
{
	for(int start=0;start<n;start++)
		minimum[start][0] = a[start];

	for(int l=1; (1<<l)<=n; l++)
	{
		int length = (1<<l);
		int half = (1<<(l-1)); // (length/2)

		for(int start=0; (start + length - 1< n); start++)
		{
			if(minimum[start][l-1] < minimum[start + half][l-1])
				minimum[start][l] = minimum[start][l-1];
			else
				minimum[start][l] = minimum[start+half][l-1];
		}
	}
}

int get(int l, int r)
{
	int k = floor(log2(r-l+1));
	if(minimum[l][k] < minimum[r-(1<<k)+1][k])
		return minimum[l][k];
	else
		return minimum[r-(1<<k)+1][k];
}

int main()
{
	ios::sync_with_stdio(false);
	int n,q,l,r;
	cin>>n;
	
	// Take Input
	f(i,n) cin>>a[i];
	preprocessing(n);

	cin>>q;
	while(q--)
	{
		cin>>l>>r;
		cout<<get(l,r)<<endl;
	}	
}