#include<iostream>
using namespace std;
int main()
{
    long long int t,i,j,a[15000],n;

    cin>>t;
    for(j=1;j<=t;j++)
    {
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        a[0]=0;
        for(i=2;i<=n;i++)
        {
            a[i]=max(a[i-1],a[i]+a[i-2]);
        }
        cout<<"Case "<<j<<": "<<a[n]<<endl;
    }
    return 0;
}
