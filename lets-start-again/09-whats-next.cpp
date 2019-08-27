// https://www.spoj.com/problems/ACPC10A/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c;
	cin.sync_with_stdio(false);
	while(true)
	{
		cin>>a>>b>>c;
		if(a==0 and b==0 and c==0)
			break;
		if(c-b == b-a)
			cout<<"AP "<<c+(b-a);
		else
			cout<<"GP "<<c*(b/a);
		cout<<"\n";
	}
}