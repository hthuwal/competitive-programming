#include<iostream>
using namespace std;
class hc{

public:
long long int jp(long long int n, long long int r)
{
    long long int nr=1,ans=1,i;
    if(n-r<r)
        r=n-r;
    for(i=1;i<=r;i++)
    {   nr=(n-i+1);
        if(nr%i==0)
        {
            ans=ans*(nr/i);
        }
        else if(ans%i==0)
        {
            ans=nr*(ans/i);
        }
        else
        {
            ans=(nr*ans)/i;
        }
    }
    cout <<ans<<endl;
}
};
int main()
{
    long long int t,a,b;
    hc jyoti;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        jyoti.jp(a-1,b-1);
    }
    return 0;
}
