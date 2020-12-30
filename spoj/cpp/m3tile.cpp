#include <bits/stdc++.h>
using namespace std;

//  f(n) = 3*f(n-2) + 2*f(n-4) + 2*f(n-6) + ....
//  f(0) = 1
//  f(2) = 3
//  f(odd) = 0
int f(int n)
{
	if (n%2 == 1) return 0;
	if (n == 0) return 1;
	if (n == 2) return 3;
	int ans = 3*f(n-2);
	for(n=n-4;n>=0; n-=2)
		ans += 2*f(n);
	return ans;
}

int main()
{
	int n;
	while(1)
	{
		scanf("%d",&n);
		if(n==-1)
			break;
		printf("%d\n",f(n));
	}
}