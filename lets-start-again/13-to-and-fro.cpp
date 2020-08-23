// https://www.spoj.com/problems/TOANDFRO/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int nc;
	string str;
	cin.sync_with_stdio(false);
	while(true)
	{
		cin>>nc;
		if(nc == 0)
			break;
		cin>>str;
		int len = str.length();
		int nr = len / nc;
		for(int i=0;i<nc;i++)
		{
			for(int j=0; j<nr; j++)
			{
				if(j%2 == 0)
					cout<<str[j*nc + i];
				else
					cout<<str[j*nc + nc - i - 1];
			}
		}
		cout<<"\n";
	}
}