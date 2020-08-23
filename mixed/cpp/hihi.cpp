#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    long long int t,n,x;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        long long int k = n;
        int count=0;
        while(n>0)
        {
            count++;
            x=(n&1);
            // cout<<x<<"\n";
            if(x==0)
                break;
            n=n>>1;
        }
        // cout<<count;
        x = 1;
        x=x<<(count-1);
        // cout<<x<<" "<<n;
        cout<<(k^x)<<endl;
    }
}
