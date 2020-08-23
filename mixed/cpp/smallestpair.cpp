#include<iostream>
using namespace std;
int main()
{
	int t,n,m1,m2,a;
	cin>>t;
	while(t--)
	{
		cin>>n;
		m1=m2=2000000;
		while(n--)
		{
			cin>>a;
			if(a<m1)
			{
				m2=m1;
				m1=a;
			}
			else if(a<m2)
			{
				m2=a;
			}
		}
		cout<<m1+m2<<endl;
	}
	return 0;
}