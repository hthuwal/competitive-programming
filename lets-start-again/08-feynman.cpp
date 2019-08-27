// https://www.spoj.com/problems/SAMER08F/

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin.sync_with_stdio(false);
	while(cin>>n)
	{
		int ans = n * (n+1) * (2*n+1);
		ans = ans / 6;
		if(n==0)
			break;
		cout<<ans<<"\n";

	}
}