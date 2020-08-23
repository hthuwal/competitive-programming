#include<bits/stdc++.h>
#define lli long long int
using namespace std;

bool verify(lli a[], lli n, lli s, lli x)
{
	lli i = 0;
	while(i<n)
	{
		if(a[i] < x)
			return false;
		else
			s -= (a[i]-x);
		i++;
	}
	return s > 0? false: true;
}

lli bsearch(lli a[], lli n, lli s) {
    lli lb = 0;
    lli ub = (lli)1e18; // could also be set to sum of array a
    while(lb<=ub)
    {
        lli mid = lb+(ub-lb)/2;
    	// cout<<lb<<" "<<ub<<" "<<mid<<" "<<verify(a, n, s, mid)<<endl;
        if(verify(a, n, s, mid))
            lb = mid + 1;
        else
            ub = mid - 1;
    }
    if(lb > 0 and verify(a, n, s, lb-1))
    	return lb-1;
    else
    	return -1;
}

int main()
{
	lli s, n;
	cin>>n>>s;
	lli a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a, a + n);
	cout<<bsearch(a, n, s);
}