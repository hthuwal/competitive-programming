// https://www.spoj.com/problems/CANDY/

#include<bits/stdc++.h>
using namespace std;

int arr[11111];

int main()
{
	int n, total;
	while(cin>>n)
	{
		if(n==-1)
			break;
		total = 0;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			total += arr[i];
		}
		if(total % n != 0)
			cout<<"-1\n";
		else
		{
			int change = 0;
			int x = total / n;
			for(int i=0;i<n;i++)
			{
				change += abs(arr[i] - x);
			}
			cout<<change / 2<<"\n";
		}

	}
}