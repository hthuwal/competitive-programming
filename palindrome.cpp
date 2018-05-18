#include<iostream>
using namespace std;
#define x 100000000
#define y 1000000007
long long int hc[x]={0};
long long int jyoti(long long int n)
{
    long long int k,i,ans;
    if(n==1)
    {
        hc[1]=26;
        return hc[1];
    }
    else if(n<=x)
    {
        if(hc[n]!=0)
            return (hc[n])%y;
        else
        {
            if(n%2==0)
                k=n/2;
            else
                k=(n/2)+1;
            for(i=0,ans=1;i<k;i++)
            {
                ans=(ans*26)%y;
            }
            hc[n]=(ans+jyoti(n-1))%y;
            return hc[n];
        }
    }
    else
    {
        if(n%2==0)
            k=n/2;
        else
            k=(n/2)+1;
        for(i=0,ans=2;i<k;i++)
        {
            ans=(ans*26)%y;
        }
        return (ans+jyoti(n-1))%y;
    }
}
int main()
{
    long long int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout <<jyoti(n)<<endl;
    }
    return 0;
}
