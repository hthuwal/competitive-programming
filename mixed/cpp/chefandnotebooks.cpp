#include<iostream>
using namespace std;
int main()
{
    int t,x,y,k,n,a,b,i,flag;
    cin>>t;
    while(t--)
    {
        cin>>x>>y>>k>>n;
        y=x-y;
        for(i=0,flag=0;i<n;i++)
        {
            cin>>a>>b;
            if(a>=y&&b<=k)
                flag=1;
        }
        if(flag==1)
            cout<<"LuckyChef"<<endl;
        else
            cout<<"UnluckyChef"<<endl;
    }
    return 0;
}
