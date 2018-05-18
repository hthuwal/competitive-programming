#include<iostream>
#include<cmath>
#define pie 4*atan(1)
using namespace std;
int main()
{
    int t,hc;
    float ans,H,theta,base,a,area;
    cin >>t;
    while(t--)
    {
        cin >>a>>H>>theta;
        theta = (theta*(pie))/180;
        base = H/tan(theta);
        if(base<=a)
            area=(base*H)/2;
        else
                 area=((H+H-(a*tan(theta)))*a)/2;
        ans=area/a;
        hc=ans/1;
        if(hc!=ans)
            ans=ans+1;
        hc=ans;
        cout <<hc<<endl;
    }
    return 0;
}
