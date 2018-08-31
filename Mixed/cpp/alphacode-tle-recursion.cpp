#include<iostream>
#include<cstdio>
using namespace std;
int hc(string jp,int i)
{
    if(i>=((jp.length())-1))
        return 1;
    else
    {
        if((10*(jp[i+0]-'0')+(jp[i+1]-'0')<=26))
        {
            return hc(jp,i+1)+hc(jp,i+2);
        }
        else
            return hc(jp,i+1);
    }
}
int main()
{
    while(1)
    {
        int k;
        string jp;
        cin >>jp;
        if(jp[0]=='0')
            break;
        else
        {
            k = hc(jp,0);
            cout << k<<endl;
        }
    }
    return 0;
}
