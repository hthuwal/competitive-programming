#include<iostream>
using namespace std;
int main()
{
    long long int a[1000006],n,maxx,minn,m,l,i,a1,a2;
    cin >> n;
    for(i=0,maxx=-1000006,minn=1000006;i<n;i++)
    {
        cin >> a[i];
        if(a[i]>maxx)
        {
            m=i;
            maxx=a[i];
        }
        if(a[i]<minn)
        {
            l=i;
            minn=a[i];
        }
    }
    for(i=0,a1=0;i<n;i++)
    {
        a1+=(a[(m+1+i)%n])*(i+1);
    }
    for(i=0,a2=0;i<n;i++)
    {
        a2+=(a[(l+i)%n])*(i+1);
    }
    cout <<max(a1,a2);
    return 0;
}
