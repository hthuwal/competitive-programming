#include<bits/stdc++.h>
using namespace std;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	int t,n,i;
	cin>>t;
	float ans;
	while(t--)
	{
		cin>>n;
		ans=0.00;
		for(i=1;i<=n;i++)
		{
			ans+=(1.00/i);
		}
		ans=ans*n;		
		printf("%0.2f\n",ans);
	}
}