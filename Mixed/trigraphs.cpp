#include<iostream>
#include<cstdio>
using namespace std;
int hc[100005][3];
int main()
{
    int n,i,temp,ans,t=0;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        t++;
        for(i=0;i<n;i++)
        {
            scanf("%d %d %d",&hc[i][0],&hc[i][1],&hc[i][2]);
        }
        if(n==2)
        {
            temp=hc[0][1]+hc[1][1];
            ans=min(temp,temp+hc[0][2]);
            ans=min(ans,temp+hc[1][0]);
        }
        else
        {
            hc[n-1][0]+=hc[n-1][1];
            hc[n-2][2]+=hc[n-1][1];
            hc[n-2][1]=min(min(hc[n-2][1]+hc[n-1][1],hc[n-2][1]+hc[n-2][2]),hc[n-2][1]+hc[n-1][0]);
            hc[n-2][0]=min(min(hc[n-2][0]+hc[n-1][1],hc[n-2][0]+hc[n-1][0]),hc[n-2][0]+hc[n-2][1]);
            for(i=n-3;i>0;i--)
            {
                hc[i][2]=min(hc[i][2]+hc[i+1][2],hc[i][2]+hc[i+1][1]);
                hc[i][1]=min(min(min(hc[i][1]+hc[i+1][1],hc[i][1]+hc[i+1][2]),hc[i][1]+hc[i+1][0]),hc[i][1]+hc[i][2]);
                hc[i][0]=min(min(hc[i][0]+hc[i+1][0],hc[i][0]+hc[i+1][1]),hc[i][0]+hc[i][1]);
            }
            hc[0][2]=min(hc[0][2]+hc[1][2],hc[0][2]+hc[1][1]);
            hc[0][1]=min(min(min(hc[0][1]+hc[1][1],hc[0][1]+hc[1][2]),hc[0][1]+hc[1][0]),hc[0][1]+hc[0][2]);
            ans=hc[0][1];
        }
        printf("%d. %d\n",t,ans);
    }
    return 0;
}
