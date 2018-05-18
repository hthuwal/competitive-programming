#include<iostream>
using namespace std;
#define x 1000000007
int main()
{
    int n,m,i,j,a[100005],b[100005],c[100005];
    cin >>n >>m;
    for(i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(i=0;i<m;i++)
    {
        cin >> b[i];
    }
    for(i=0;i<m;i++)
    {
        cin >> c[i];
    }
    for (i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(j%b[i]==0)
            {
                a[j]=((a[j]%x)*(c[i]%x))%x;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        cout << a[i]<<' ';
    }
}
