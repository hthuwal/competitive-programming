#include<iostream>
using namespace std;
int main()
{
	long long int n,i,hc,jp,t,j,count;
	cin>>t;
	while(t--)
	{
		cin>>n;
		hc=-1;jp-1;
		for(i=0,j=0,count=0;i<n;i++)
		{
			cin>>hc;
			if(hc>=jp)
			{
				count+=(i-j+1);
				jp=hc;
			}
			else
			{
				count++;
				jp=hc;
				j=i;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}