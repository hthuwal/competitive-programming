#include <iostream>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <cmath>
#define f(i,a,b) for(long long int i=a;i<b;i++)
using namespace std;
long long int M[110];
double func(double r,double m)
{
	double x=0;
	f(i,0,m+1)
	{
		x+=M[i]*pow((1+r),m-i);
	}
	return x;
}
double solvemid(double l,double h,long long int m)
{
	double x,mid;
	do{
		mid = (l+h)/2;
		if(l==h)
			break;
		x = func(mid,m);
		if(x>0)
		{
			h=mid;
		}
		else if(x<0)
		{
			l=mid;
		}
		 // cout<<l<<" "<<mid<<" "<<h<<" : "<<x<<"\n";
	}while(fabs(x-0)>=0.00001 && mid <= 0.9999);
	return mid;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	long long int T,m;
	cin>>T;
	f(t,1,T+1)
	{
		cin>>m;
		f(i,0,m+1)
			cin>>M[i];
		M[0]=-M[0];
		// cout<<func(0.1,m);
		double l=-2,h=2;
		for(int i=10;i>=1;i--)
		{
			double x = func(-1*(i/10.0),m);
			// cout<<x;
			if(x<0 && l==-2)
			{
				l=-1*(i/10.0);
			}
			if(x>0 && h==2)
			{
				h=-1*(i/10.0);
			}
		}
		f(i,0,11)
		{
			double x = func(i/10.0,m);
			// cout<<x<<endl;
			if(x<0 && l==-2)
			{
				l=i/10.0;
			}
			if(x>0 && h==2)
			{
				h=i/10.0;
			}
		}
		// cout<<l<<" "<<h;
		cout<<"Case #"<<t<<": ";
        printf("%0.12lf\n",solvemid(l,h,m));
	}
}
