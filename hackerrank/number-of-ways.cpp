#include<bits/stdc++.h>
#define lli long long int
#define M 1000000007
using namespace std;

string a, b, c, ab, ba;

lli recursive(string ab, int i, string str)
{
	if(str.length() == c.length())
	{
		cout<<str<<" "<<c<<endl;
		if(str == c)
			return 1;
		else
			return 0;
	}
	else if(i >= ab.length())
		return 0;
	else if(str.length() < c.length())
		return (recursive(ab, i+1, str+ab[i]) + recursive(ab, i+1, str))%M;

	return 0;
}
int main()
{
	cin>>a>>b>>c;
	ab = a + b;
	ba = b + a;
	// cout<<ab;
	cout<<(recursive(ab, 0, "") + recursive(ba, 0, ""))%M;
	
}