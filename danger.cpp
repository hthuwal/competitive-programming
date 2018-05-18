#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    string hc;
    int a,b,z,i;
    int p,ans;
    char c;
    while(1)
    {
    cin>>hc;
    a=hc[0]-'0';
    b=hc[1]-'0';
    z=hc[3]-'0';
    if(a==0&&b==0&&z==0)
        break;
    else
    {
        p=(10*a+b)*pow(10,z);
        for(i=0;;i++)
        {
            if(pow(2,i)>p)
                break;
        }
        ans=1+(p-pow(2,i-1))*2;
        cout<<ans<<endl;
    }
    }
    return 0;
}
