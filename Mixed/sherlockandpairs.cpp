#include<iostream>
using namespace std;
int main()
{
    long long int t,n,x,i;
    long long int ans;
    cin >>t;
    while(t--)
    {
        int hc[1000006]={0};
        cin >>n;
        while(n--)
        {
            cin >>x;
            hc[x]++;
        }
        for(i=0,ans=0;i<1000006;i++)
        {
            n=hc[i];
            ans=ans+((n*(n-1))/2);
        }
        ans=ans*2;
        cout <<ans<<endl;
    }
    return 0;
}
