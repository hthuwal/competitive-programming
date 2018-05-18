#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int i,temp,ans,n;
    for(i=0,temp=0,ans=0;i<10;i++)
    {
        cin>>n;
        temp=temp+n;
        if(abs(temp-100)<abs(ans-100))
            ans=temp;
        else if(abs(temp-100)==abs(ans-100))
        {
            if(temp>ans)
                ans=temp;
        }
    }
    cout<<ans;
}
