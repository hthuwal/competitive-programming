#include<iostream>
using namespace std;
int main()
{
	int t,i,j,flag,k,n;
	cin>>t;
	while(t--)
	{
		string jp;
		cin>>n>>k;
		int hc[110]={0};
		for(i=0;i<n;i++)
		{
			cin>>jp;
			hc[jp.length()]++;
		}
		for(i=0,flag=1;i<110;i++)
		{
			if(hc[i]!=0 && (hc[i]%k)!=0)
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
			cout<<"Possible"<<endl;
		else
			cout<<"Not possible"<<endl;
	}
}