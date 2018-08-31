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
		printf("%4d, ", cls[i].first);
	printf("\n");
	for(int i=0; i<n; i++)
		printf("%4d, ", cls[i].second);
	printf("\n\n");
}

bool comp1(pii a, pii b)
{
	if(a.second < b.first) return true;
	return false;
}

bool comp2(pii a, pii b)
{
	if(a.first >= b.second) return false;
	return true;
}

int ans(int n)
{
	dp[0]=0;
	sum[0]=0;
	int l, h;
	printf("%s%4s%4s%4s%4s\n","i","l","h","sl","sh");
	for(int i=0; i<n; i++)
	{
		dp[i+1] = 0;
		sum[i+1] = sum[i];
		l = lower_bound(cls, cls+i-1, cls[i], comp1) - cls;
		h = upper_bound(cls, cls+i, cls[i], comp2) - cls;
		printf("%d%4d%4d%4d%4d\n", i, l, h, sum[h], sum[l]);
		if(h >= l)
			dp[i+1] = (sum[h] - sum[l]) % M;
		dp[i+1] = (dp[i+1] + 1) % M;
		sum[i+1] = (sum[i] + dp[i+1]) % M;
	}
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