#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
	#endif
    long long int t,n,k;
    cin>>t;
    while(t--)
    {
    	cin>>n;
    	if(n==1 || n==2)
    		cout<<1<<endl;
    	else
    	{
    		n++;
    		k=n/4;
    		k=2*k-1;
    		if(n%4==0||n%4==1||n%4==3)
    			cout<<k<<endl;
    		else
    			cout<<k+1<<endl;
    	}
    }
}