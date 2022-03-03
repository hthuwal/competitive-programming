#include<stdio.h>
int main()
{
    int t;
    long long int n,hc,jp,count;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        hc=1;
        count=0;
        while(1)
        {
            hc=hc*5;
            jp=n/hc;
            if(jp==0)
                break;
            else
                count=count+jp;
        }
        printf("%lld\n",count);
    }
    return 0;
}
