#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    string a;
    long long int n,hc=0,jp=0,mylove=0,ans,temp;
    cin>>n;
    while(n--)
    {
        cin>>a;
        if(a[2]=='2')
            hc++;
        else if(a[0]=='3'&&a[2]=='4')
            jp++;
        else
            mylove++;
    }
    ans=1;
    ans+=hc/2+(hc%2);
    temp=2*(hc%2);
    ans+=jp;
    temp+=jp;
    if(temp<mylove)
    {
        temp=mylove-temp;
        temp%4==0?ans+=(temp/4):ans+=(temp/4)+1;
    }
    cout<<ans;
    return 0;
}
