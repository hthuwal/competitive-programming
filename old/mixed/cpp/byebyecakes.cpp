#include <bits/stdc++.h>
using namespace std;

void hc(vector<int> a,vector<int> b)
{
	vector<double> c;
	double max= DBL_MIN;
	int j=-1;
	for(int i=0;i<4;i++)
	{
		c.push_back((double)a[i]/b[i]);
		if(c[i]>max)
		{
			max=c[i];
			j=i;
		}
	}
	c[j]=ceil(c[j]);
	double x =c[j];
	// cout<<c[j]<<endl;	
	for(int i=0;i<4;i++)
	{
		c[i]=((x*b[i])-a[i]);
		cout<<(int)c[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	vector<int> a(4,0);
	vector<int> b(4,0);
	while(1)
	{
		cin>>a[0]>>a[1]>>a[2]>>a[3];
		cin>>b[0]>>b[1]>>b[2]>>b[3];
		if(a[0]==-1)
			break;
		else if(a[0]==0 && a[1]==0 && a[2]==0 && a[3]==0)
			cout<<"0 0 0 0"<<endl;
		else
			hc(a,b);
	}
}