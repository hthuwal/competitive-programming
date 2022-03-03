#include<iostream>
#define x 100010
using namespace std;
int main()
{
    int t,i,temp,max,n;
    cin>>t;
    while(t--)
    {
        int hc[x]={0};
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>temp;
            hc[temp]++;
        }
        for(i=0,max=0;i<x;i++)
        {
            if(hc[i]>max)
                max=hc[i];
        }
        cout<<n-max<<endl;
    }
    return 0;
}
