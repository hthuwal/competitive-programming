#include <bits/stdc++.h>
#define pii pair<int, int>
#define lli long long int
#define M 100000000
using namespace std;

pair<int, int> cls[100001];
lli dp[100001];
lli sum[100001];

bool comp(pii a, pii b)
{
	if(a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

void print(int n)
{
	for(int i=0; i<n; i++)
	{
		printf("%d %d, ", cls[i].first, cls[i].second);
	}
	printf("\n");
}

bool comp1(pii a, pii b)
{
	if(a.second < b.first) return true;
	return false;
}

bool comp2(pii a, pii b)
{
	if(a.first < b.second) return true;
	return false;
}

int ans(int n)
{
	dp[0]=0;
	sum[0]=0;
	int l, h;
	// printf("%d\n", sum[n]);
	for(int i=0; i<n; i++)
	{
		dp[i+1] = 0;
		l = lower_bound(cls, cls+i, cls[i], comp1) - cls;
		h = upper_bound(cls, cls+i, cls[i], comp2) - cls;
		printf("cls[i]:(%d,	%d l:%d h:%d, ", cls[i], l, h);
		if(h >= l)
			dp[i+1] = (sum[h-1+1] - sum[l-1+1]) % M;
		dp[i+1] = (dp[i+1] + 1) % M;
		sum[i+1] = (sum[i] + dp[i+1]) % M;
	}
	printf("\n");
	for(int i=0;i<=n;i++)
		printf("%d, ",dp[i]);
	printf("\n");

	for(int i=0;i<=n;i++)
		printf("%d, ",sum[i]);
	printf("\n");
	return sum[n];
}

int main()
{
	int a, b, n;
	freopen("in.txt", "r", stdin);
	while(1){
		scanf("%d", &n);
		if(n==-1) break;
		for(int i=0;i<n;i++){
			scanf("%d %d",&a, &b);
			cls[i] = make_pair(a,b);
		}
		sort(cls, cls+n);
		print(n);
		printf("%08d\n", ans(n));
	}
}