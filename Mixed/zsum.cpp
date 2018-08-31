#include <iostream>
#include <cstdio>
#include <cmath>
#define M 10000007
using namespace std;
long long int exponent(long long int a,long long int x)
{
    if(a==1)
        return 1;
    else if(x==1)
        return a%M;
    else if(x==2)
        return ((a%M)*(a%M))%M;
    else if(x%2==0)
    {
        long long int b = exponent(a,x/2);
        return ((b%M)*(b%M))%M;
    }
    else
    {
        long long int b = exponent(a,x/2);
        return ((((b%M)*(b%M))%M)*(a%M))%M;
    }
}
int main()
{
	#ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
	#endif
    
    long long int n,k;
    while(1)
    {
        cin>>n;
        cin>>k;
        if(n==0 && k==0)
            break;
        long long int s,p;
        s=0;
        p=0;
        int a=(2*((exponent(n-1,k))%M))%M;
        int b=(2*((exponent(n-1,n-1))%M))%M;
        int c=(exponent(n,k))%M;
        int d=(exponent(n,n))%M;
        cout<<(((((a+b)%M)+c)%M)+d)%M<<endl;
    }
}