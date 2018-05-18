#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int t;
    double r,ans;
    cin>>t;
    while(t)
    {
        cin>>r;
        ans = (4 * r * r)+0.25;
        printf("Case %d: %0.2f",t,ans);
        t--;
    }
    return 0;
}

