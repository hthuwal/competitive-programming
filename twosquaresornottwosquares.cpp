#include<iostream>
#include<cmath>
using namespace std;
int primeFactors(long long int n)
{
    long long int hc;
    while (n%2 == 0)
    {
        n = n/2;
    }
    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    for (long long int i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        hc=0;
        while (n%i == 0)
        {
            if(i%4==3)
            {
                hc++;
            }
            n = n/i;
        }
        if(hc%2!=0)
            return 0;
    }
    if(n>2&&n%4==3)
    {
        return 0;
    }
    return 1;
}

int main()
{
    long long int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(primeFactors(n)==1)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
