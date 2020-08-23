// https://www.spoj.com/problems/FASHION/

#include<bits/stdc++.h>
using namespace std;

#define lli long long int

int men[1111];
int wmn[1111];

int main()
{
	int t,n;
	cin.sync_with_stdio(false);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>men[i];

		for(int i=0;i<n;i++)
			cin>>wmn[i];
		
		sort(men, men + n);
		sort(wmn, wmn + n);

		lli sum = 0;
		for(int i=0;i<n;i++)
			sum += men[i] * wmn[i];

		cout<<sum<<"\n";
	}
}