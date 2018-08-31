#include<iostream>
using namespace std;

int gcd(int a,int b)
{
	while(b!=0)
	{
		int q = a/b,temp;
		temp = b;
		b = a%b;
		a = temp;
	}
	return a;
}
/**
 * to get c litre water using a litre and b litre jugs => ax+by=c (diphontine equation)
 * must have integral solution which is possible if c%gcd(a,b)==0; 
 */
int main()
{
	int t,a,b,c;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c;
		if(c<=a || c<=b)
		{
			if(c%gcd(a,b)==0)
				cout<<"YES";
			else
				cout<<"NO";
		}
		else 
			cout<<"NO";
		cout<<endl;
	}
}