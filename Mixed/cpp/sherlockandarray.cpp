#include<iostream>
int hc[100005],jp[100005],mylove[100005];
using namespace std;
int main()
{
    int t,n,i,flag;
    cin >> t;
    while(t--)
    {
        hc[0]=0;
        cin >> n;
        for(i=0;i<n;i++)
        {
            cin >> mylove[i];
            if(i!=0)
            {
                hc[i]=hc[i-1]+mylove[i-1];
            }
        }
        jp[n-1]=0;
        for(i=n-2;i>=0;i--)
        {
            jp[i]=jp[i+1]+mylove[i+1];
        }
        for(i=0,flag=0;i<n;i++)
        {
            if(hc[i]==jp[i])
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            cout << "YES"<<endl;
        else
            cout << "NO"<<endl;
    }
    return 0;
}
