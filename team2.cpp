#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	long long int a[5],t;
	t=0;
	multiset<int> hc;
	
	while(cin>>a[0]>>a[1]>>a[2]>>a[3])
	{

		t++;
		hc.clear();
		
		hc.insert(a[0]);
		hc.insert(a[1]);
		hc.insert(a[2]);
		hc.insert(a[3]);

		hc.erase(hc.begin());
		hc.erase(hc.begin());

		long long int max1 = *(hc.begin());
		hc.erase(hc.begin());
		long long int max2=*(hc.begin());
		cout<<"Case "<<t<<": "<<max1+max2<<"\n";
	}
}