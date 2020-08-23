/**
 * no. marbles required : 5 12 22 35 .....
 * f(n)=f(n-1)+7+(n-2)*3
 * solving by substitution we get
 * f(n)=f(2)+7(n-2)+(3/2)(n-2)(n-1)
 */
		#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,ans;
	while(1)
	{
		cin>>n;
		if(n==0)
			break;
		else if(n==1)
			ans=5;
		else if(n==2)
			ans=12;
		else
			ans=12+7*(n-2)+((3)*(n-2)*(n-1))/2;

		cout<<ans<<"\n";
	}

}