#include <bits/stdc++.h>
#define lli long long int
#define sent
#define f(i,n) for(int i=0;i<n;i++)

using namespace std;

int hc_hash[200005];
int arr[7100];
unordered_map<int, vector<int>> hash_2;

lli add(lli z, int j)
{
	int num = 0;
	if(z != -1 and z < 200005 and hash_2.find(z) != hash_2.end())
		num = hash_2[z].end() - upper_bound(hash_2[z].begin(), hash_2[z].end(), j);

	return num;
}

lli solve(int a[], int n)
{
	lli ans = 0;
	for(int i=0;i<n;i++)
	{
		lli x = arr[i];
		for(int j=i+1; j<n;j++)
		{
			lli y = arr[j];
			// for(int k=j+1;k<n;k++)
			// {
			// 	lli z = arr[k];
			// 	if(x==y*z or y==z*x or z==x*y)
			// 		ans++;
			// }
			lli z1 = (x * y);
			lli z2 = ((y!= 0 and x % y == 0)? x/y: -1);
			lli z3 = ((x!= 0 and y % x == 0)? y/x: -1);
			// cout<<x<<" "<<y<<" "<<z1<<" "<<z2<<" "<<z3<<endl;

			if(z1 == z2 and z2 == z3)
				ans += add(z1, j);
			else if(z1 == z2)
				ans += add(z1, j) + add(z3, j);
			else if(z3 == z2)
				ans += add(z1, j) + add(z3, j);
			else if(z1 == z3)
				ans += add(z1, j) + add(z2, j);
			else
				ans += add(z1, j) + add(z2, j) + add(z3, j);
		}
	}
	return ans;
};

int main()
{
	int n, t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&n);
		hash_2.clear();
		f(i, n)
		{
			scanf("%d",&arr[i]);
			hc_hash[arr[i]]++;
			hash_2[arr[i]].push_back(i);
		}

		for(auto &each: hash_2)
			sort(each.second.begin(), each.second.end());

		printf("Case #%d: %lld\n", i, solve(arr, n));
	}
}