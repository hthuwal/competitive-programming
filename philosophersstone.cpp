#include<iostream>
using namespace std;
int main()
{
    int hc[150][150],t,h,w,i,j,temp,ans;
    cin>>t;
    while(t--)
    {
        cin >>h>>w;
        for (i=0;i<h;i++)
        {
            for(j=0;j<w;j++)
            {
                cin >>hc[i][j];
            }
        }
        for(i=h-2;i>=0;i--)
        {
            for(j=0;j<w;j++)
            {
                if(j==0)
                {
                    hc[i][j]=max(hc[i][j]+hc[i+1][j],hc[i][j]+hc[i+1][j+1]);
                }
                else if(j==(w-1))
                {
                    hc[i][j]=max(hc[i][j]+hc[i+1][j],hc[i][j]+hc[i+1][j-1]);
                }
                else
                {
                    temp=max(hc[i][j]+hc[i+1][j],hc[i][j]+hc[i+1][j+1]);
                    hc[i][j]=max(hc[i][j]+hc[i+1][j-1],temp);
                }
            }
        }
        ans=hc[0][0];
        for(i=1;i<w;i++)
        {
            if(hc[0][i]>ans)
                ans=hc[0][i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
