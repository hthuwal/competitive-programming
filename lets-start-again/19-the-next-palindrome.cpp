#include<bits/stdc++.h>
using namespace std;

string increment(string in)
{
	int l = in.length();
	int i = l/2 - 1;
	int j = l % 2 == 0? l/2 : l/2 + 1;
	int x;
	int toadd = 1;

	if(l%2 != 0)
	{
		x = in[l/2] - '0';
		x++;
		toadd = x / 10;
		in[l/2] = '0' + x % 10;
	}

	while(i>=0 and j<=l-1)
	{
		if(toadd == 0)
			break;

		x = in[i] - '0';
		x++;
		toadd = x / 10;
		in[i] = '0' + x % 10;
		in[j] = in[i];
		i--;j++;
	}

	if(toadd == 1)
		in = "1" + in + "1";
	return in;
}

int main()
{
	int t,l,i,j;
	cin.sync_with_stdio(false);
	cin>>t;

	string in, org;
	while(t--)
	{
		cin>>in;
		org = in;
		l = in.length();
		i = l/2 - 1;
		j = l % 2 == 0? l/2 : l/2 + 1;

		bool doweneedtoadd = false;

		while(i>0 and j<l-1)
		{
			if(in[i] == in[j])
				continue;

			if(in[i] < in[j])
				doweneedtoadd = true;

			in[j] = in[i];
			i--;j++;
		}
		if(in == org)
			doweneedtoadd = true;

		if(doweneedtoadd)
			increment(in);

		cout<<in<<"\n";
	}
}