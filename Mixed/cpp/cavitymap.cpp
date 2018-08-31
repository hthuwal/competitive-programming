#include <iostream>
using namespace std;

int main()
{
    string hc[110];
    int n,x,a,b,c,d,i,j;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> hc[i];
    }
    for(i=1;i<n-1;i++)
    {
        for(j=1;j<n-1;j++)
        {
            x=hc[i][j]-'0';
            a=hc[i+1][j]-'0';
            b=hc[i-1][j]-'0';
            c=hc[i][j+1]-'0';
            d=hc[i][j-1]-'0';
            if(x>a&&x>b&&x>c&&x>d)
            {
                hc[i][j]='X';
            }
        }
    }
    for(i=0;i<n;i++)
    {
        cout <<hc[i]<<endl;
    }
    return 0;
}
