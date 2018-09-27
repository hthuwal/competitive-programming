#include <bits/stdc++.h>
using namespace std;

int main()
{
	int q;
	string str;
	scanf("%d",&q);
	while(cin>>str)
	{
		char prev = str[0];
		int count = 0;
		for(int i=1;i<str.length();i++)
		{
			if(str[i] == prev)
				count += 1;
			else
				prev = str[i];
		}
		printf("%d\n", count);
	}
}