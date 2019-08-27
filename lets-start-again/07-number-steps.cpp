// https://www.spoj.com/problems/NSTEPS/

#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, x, y;
	cin.sync_with_stdio(false);
	cin>>n;
	while(n--)
	{
		cin>>x>>y;
		if(x==y or x-y==2)
		{
			if(x % 2 == 0)
				cout<<(x+y);
			else
				cout<<(x+y - 1);
		}
		else
		{
			cout<<"No Number";
		}
		cout<<"\n";
	}
}