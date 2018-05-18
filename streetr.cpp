#include <iostream>
#include <algorithm>
using namespace std;
long int in[110000];
long int diff[110000];
int n;
void input()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>in[i];
	}
}
void difference()
{
	long int min = 1000000000;
	for(int i=1;i<n;i++)
	{
		diff[i-1]=in[i]-in[i-1];
		if(diff[i]<min)
			min=diff[i];
	}
}
long int gcd(long int a,long int b)
{
	return (b==0?a:gcd(b,a%b));
}
int main()
{
	input();
	sort(in,in+n);
	difference();
	long int ans = gcd(diff[0],diff[1]);
	for(int i=2;i<n-1;i++)
		ans = gcd(ans,diff[i]);
	long int hc=0;
	for(int i=0;i<n-1;i++)
		hc+=((diff[i]/ans)-1);
	cout<<hc;
}
