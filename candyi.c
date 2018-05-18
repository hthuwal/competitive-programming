#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    while(1)
    {
        int hc[11000]={0},i,n,sum,ans,jp;
        scanf("%d",&n);
        if(n==-1)
            break;
        else
        {
            for(i=0,sum=0;i<n;i++)
            {
                scanf("%d",&hc[i]);
                sum=sum+hc[i];
            }
            ans=sum;
            if(sum%n!=0)
                printf("-1\n");
            else
            {
                jp=sum/n;
                for(i=0,ans=0;i<n;i++)
                {
                    ans= ans+ abs(hc[i]-jp);
                }
                ans=ans/2;
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
