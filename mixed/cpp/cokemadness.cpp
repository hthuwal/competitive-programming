#include<iostream>
using namespace std;
int main()
{
	long long int t,n,life,ans,x,i;
	cin>>t;
	i=1;
	while(i<=t)
	{
		cin>>n;
		life=1;
		ans=1;
		while(n--)
		{
			cin>>x;
			life+=x;
			if(life<=0)
			{
				ans+=life*(-1)+1;
				life=1;
			}
		}
		cout<<"Scenario #"<<i<<": "<<ans<<endl;
		i++;
	}
}