#include<iostream>
#include<cmath>
using namespace std;
string hc(int x)
{
    int i;
    if(x==1)
        return "2(0)";
    else
    {
        for(i=0;pow(2,i+1)<=x;i++)
        {
        }
        if(x-pow(2,i)!=0)
            if(i!=1)
                return "2("+hc(i)+")+"+hc(x-pow(2,i));
            else
                return  "2+"+hc(x-pow(2,i));
        else
            if(i!=1)
                return "2("+hc(i)+")";
            else
                return "2";
    }
}
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<n<<"="<<hc(n)<<endl;
    }
}

//137=2(2(2)+2+2(0))+2(2+2(0))+2(0)
//1315=2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)
//73=2(2(2)+2)+2(2+2(0))+2(0)
//136=2(2(2)+2+2(0))+2(2+2(0))
//255=2(2(2)+2+2(0))+2(2(2)+2)+2(2(2)+2(0))+2(2(2))+2(2+2(0))+2(2)+2+2(0)
//1384=2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2)+2(2(2)+2(0))+2(2+2(0))
//16385=2(2(2+2(0))+2(2)+2)+2(0)///