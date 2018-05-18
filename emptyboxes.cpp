/**
 * see picture in the folder for derivation
 * emptyboxes.jpg
 */
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
		int test,n,k,t,f;
	cin>>test;
	while(test--)
	{
		cin>>n>>k>>t>>f;
		cout<<(n+(k*(f-n))/(k-1))<<"\n";
	}
}