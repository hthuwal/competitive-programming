#include <bits/stdc++.h>
#define f(i, n) for(int i=0;i<n;i++)

using namespace std;
int parent[55555];
int size[55555];
int eat[55555];

int find(int i)
{
	if(parent[i] == i)
		return i;
	return parent[i] = find(parent[i]);
}

void uni(int i, int j)
{
	int pi = find(i);
	int pj = find(j);
	if(pi != pj)
	{
		if(size[pi] < size[pj])
		{
			parent[pi] = pj;
			size[pj] += size[pi];
		}
		else
		{
			parent[pj] = pi;
			size[pi] += size[pj];
		}
	}
}

int main()
{
	int t,n,k,x,a,b;
	ios::sync_with_stdio(false);
	for(cin>>t;t--;)
	{
		int count = 0;
		cin>>n>>k;		

		// initialization
		f(i,n)
		{
			parent[i]=i; 
			size[i]=1; 
			eat[i]=-1;
		}

		f(i, k)
		{
			cin>>x>>a>>b;
			if(a > n || a<=0 || b>n || b<=0)
				count++;
			else if(x==1)
			{
				a--; b--;
				int pa = find(a);
				int pb = find(b);

				if(eat[pa] == pb)
					count ++;
				else if(eat[pb] == pa)
					count ++;
				else
				{
					uni(a, b);
					eat[a] = find(eat[a]);
					eat[b] = find(eat[b]);
				}
			}
			else if(x==2)
			{
				a--; b--;
				int pa = find(a);
				int pb = find(b);
				if(eat[pa]!=-1 and eat[pb] == pa)
					count ++;
				else
				{
					eat[pa] = pb;
				}
			}
			// for(int i=0;i<4;i++)
			// 	cout<<parent[i]<<" ";
			// cout<<endl;
			// for(int i=0;i<4;i++)
			// 	cout<<eat[i]<<" ";
			// cout<<endl;
		}

		cout<<count<<endl;
	}
	return 0;
}