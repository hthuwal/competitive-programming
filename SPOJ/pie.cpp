/**
 * https://www.spoj.com/problems/PIE/
 *
 * SPOJ: PIE
 */
#include<bits/stdc++.h>
using namespace std;
double arr[10001];
double pi = M_PI;
int n, f;

/**
 * @param  size of slice that everyone will get 
 * @return True if it is possible to give everyone a slice of size "slice"
 */
bool verify(double slice)
{
	int k = f;
	for(int i=0;i<n;i++)
	{
		if(k<=0)
			return true;
		double temp = arr[i];
		while(temp >= slice)
		{
			temp -= slice;
			k--;
		}
	}
	if(k<=0)
		return true;
	return false;
}

/**
 * Binary Search on the target value of slice
 */
double bs(double l, double h)
{
	while(h-l >= 0.00001)
	{
		double mid = l + (h-l) / 2.0;
		if(verify(mid))
			l = mid;
		else
			h = mid;
	}
	return l;
}

int main()
{
	int t, x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&f);
		double maxhc = 0;
		f++;
		for(int i=0;i<n;i++)
		{
			scanf("%lf",&arr[i]);
			arr[i] = arr[i] * arr[i] * pi;
			if(arr[i] > maxhc)
				maxhc = arr[i];
		}
		printf("%0.4f\n", bs(0, maxhc));
	}
}