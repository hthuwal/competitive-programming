#include<stdio.h>
#define x 1000006
int hc[x]={0};
int check(long long int n)
{
    if(n<2)
        return 0;
    else if(hc[n]==n)
        return 1;
    else
        return 0;
}
int main()
{
    int n,i,j,flag;
    long long int y;
    for(i=2;i<x;i++)
    {
        hc[i]=i;
    }
    for(i=2;i<x;i++)
    {
        for(j=i+i;j<x;j+=i)
        {
            hc[j]=0;
        }
    }
    while(1)
    {
    scanf("%d",&n);
    if(n==0)
        break;
    for(i=0;i<x;i++)
    {
        if(hc[i]!=0)
        {
            for(j=0,flag=0;j<x;j++)
            {
                if(hc[j]!=0)
                {
                    y=n-pow(hc[i],3)-pow(hc[j],2);
                    if(check(y)==1)
                    {
                        flag=1;
                        break;
                    }
                    else if(y<0)
                        break;
                }
            }
            if(flag==1)
            {
                break;
            }
        }
    }
    if(flag==1)
    {
        printf("%lld %d %d\n",y,hc[j],hc[i]);
    }
    else
    {
        printf("0 0 0\n");
    }
    }
    return 0;
}
