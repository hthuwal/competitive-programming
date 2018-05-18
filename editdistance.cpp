#include<iostream>
using namespace std;
int main()
{
    int t,i,j;
    static int mylove[2100][2100];
    string a,b;
    cin>>t;
    while(t--)
    {
        cin>>a;
        cin>>b;
        int hc = a.length();
        int jp = b.length();
        for(i=0;i<=hc;i++)
            mylove[i][0]=i;
        for(j=0;j<=jp;j++)
            mylove[0][j]=j;
        for(i=1;i<=hc;i++)
        {
            for(j=1;j<=jp;j++)
            {
                int m=(a[i-1]==b[j-1]?0:1);
                int temp1 = min(mylove[i-1][j]+1,mylove[i][j-1]+1);
                int temp2 = mylove[i-1][j-1]+m;
                mylove[i][j] = min(temp1,temp2);
            }
        }
        cout<<mylove[hc][jp]<<endl;
    }
    return 0;
}
