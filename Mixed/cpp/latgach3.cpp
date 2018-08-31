#include <bits/stdc++.h>
using namespace std;

int ans(int n)
{
	if(n<0)
		return 0;
	if(n==0)
		return 1;
	return 3*ans(n-2) + 2*ans(n-4); 
}

int main()
{
	cout<<ans(8);
}