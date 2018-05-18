#include<iostream>
#define x 100000
using namespace std;

int main()
{
    int a,d,i,h,j,p,hc[15],jp[15];
    while(1)
    {
        cin>>a>>d;
        if(a==0&&d==0)
            break;
        else
        {
            for(i=0,h=x;i<a;i++)
            {
                cin>>hc[i];
                if(hc[i]<h)
                    h=hc[i];
            }
            for(i=0,j=x,p=x;i<d;i++)
            {
                cin>>jp[i];
                if(jp[i]<j)
                {
                    p=j;
                    j=jp[i];
                }
                else if(jp[i]<p)
                {
                    p=jp[i];
                }
            }
            if(h<p)
            {
                cout<<'Y'<<endl;
            }
            else
            {
                cout<<'N'<<endl;
            }
        }
    }
    return 0;
}
