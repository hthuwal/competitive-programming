#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t,d,v,l,r;
	ios::sync_with_stdio(false);
	for(cin>>t;t--;)
	{
		cin>>d>>v>>l>>r;
		int total_lanterns = d/v;
		int invisible_lanterns = r/v - ((l-1)/v);
		cout<<total_lanterns - invisible_lanterns<<endl;
	}
}