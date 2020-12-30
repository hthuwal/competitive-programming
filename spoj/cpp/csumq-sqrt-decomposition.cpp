/**
 * https://www.spoj.com/problems/CSUMQ/
 *
 * No Updates, Only Range Sum
 *
 * Online query porcessing, Square root decompositoin
 *
 * O(q * sqrt(n))
 */

#include <bits/stdc++.h>
using namespace std;

#define N 100005
#define lli long long int

lli sums[N];
lli arr[N];
int n;

void preprocess()
{
	int size = floor(sqrt(n));
	int k = 0;
	lli sum = 0;
	for(int i=0;i<n;i++)
	{
		if(i!=0 and (i%size == 0))
		{
			sums[k++] = sum;
			sum = 0;
		}
		sum += arr[i];
	}
	if(sum != 0)
		sums[k++] = sum;
}

lli get(int x)
{
	int size = floor(sqrt(n));
	int k = x/size;
	lli sum =0;
	for(int i=0;i<k;i++)
	{
		sum += sums[i];
	}
	for(int i=k*size;i<=x;i++)
		sum += arr[i];
	return sum;
}

int main()
{
	int a, b, c, x;
	ios::sync_with_stdio(false);

	cin>>n;
	memset(sums, 0, sizeof(sums));
	for(int i=0;i<n;i++)
		cin>>arr[i];
	preprocess();
	cin>>c;
	while(c--)
	{
		cin>>a>>b;
		if(a==0)
			cout<<get(b)<<"\n";
		else
			cout<<get(b)-get(a-1)<<"\n";
	}
}