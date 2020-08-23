#include<iostream>
int hc[100005];
using namespace std;
int main()
{
    int t,n,i,ans;
    cin >>t;
    while(t--)
    {
        cin >>n;
        for(i=0;i<n;i++)
        {
            cin >> hc[i];
            if(((i+1)*(n-i))%2==0)
            {
                hc[i]=0;
            }
        }
        ans=hc[0];
        for(i=1;i<n;i++)
        {
            ans=ans^hc[i];
        }
        cout <<ans<<endl;
    }
    return 0;
}
