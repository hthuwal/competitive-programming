#include <bits/stdc++.h>
using namespace std;

int cumsum[100];
string str;
int solve(int l, int value)
{
	// cout<<str[l]<<" "<<value<<"\n";
	if(l==-1)
	{
		return 1;
	}

	int v;
	int ans=0;
	for(int i=l; i>=0; i--)
	{
		if(i==0)
			v = cumsum[l];
		else
			v = cumsum[l]-cumsum[i-1];

		if(v <= value)
			ans += solve(i-1, v);
	}
	return ans;
}

int main()
{
	int t = 0;
	while(1)
	{
		cin>>str;
		if(str=="bye")
			break;
		t++;
		cumsum[0]=str[0]-'0';
		for(int i=1;i<str.length();i++)
			cumsum[i] = cumsum[i-1] + str[i] - '0';
		// cout<<str<<"\n";
		// for(int i=0; i<str.length();i++)
		// 	cout<<cumsum[i]<<" ";
		cout<<t<<". "<<solve(str.length()-1, 1000000000)<<"\n";
	}
}
