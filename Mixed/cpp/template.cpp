#include <iostream>
#include <cstdio>
#include <algorithm>
#include <ctime>
#define f(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int T;
	cin>>T;
	f(t,1,T+1)
	{
		cout<<"Case #"<<t<<": ";
	}
}