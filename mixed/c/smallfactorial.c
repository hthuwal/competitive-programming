#include<stdio.h>
int main()
{
    int t,n,i,j,temp,carry;
    scanf("%d",&t);
    while(t--)
    {
    int hc[200]={0};
    hc[0]=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=0,carry=0;j<200;j++)
        {
            temp=hc[j]*i+carry;
            hc[j]=temp%10;
            carry=temp/10;
        }
    }
    for(i=199;i>=0;i--)
    {
        if(hc[i]!=0)
            break;
    }
    for(;i>=0;i--)
    {
        printf("%d",hc[i]);
    }
    printf("\n");
    }
    return 0;
}
