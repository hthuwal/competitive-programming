#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int a,ans,t;
    char b;
    cin>>t;
    while(t--)
    {
    cin>>a>>b;
    ans=a;
    while(b!='=')
    {
        cin >>a;
        if(b=='+')
            ans+=a;
        else if(b=='-')
            ans-=a;
        else if(b=='*')
            ans*=a;
        else if(b=='/')
            ans/=a;
        cin>>b;
    }
    cout<<ans<<endl;
    }
    return 0;
}
