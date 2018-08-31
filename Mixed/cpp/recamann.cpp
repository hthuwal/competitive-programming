#include<iostream>
#include<cstdio>
using namespace std;
int hc[10000000]={0};
int jp[10000000]={0};
int main()
{
    int am,i,n;
    hc[0]=1;
    for(i=0;i<500005;i++)
    {
        if(i==0)
            jp[i]==0;
        else
        {
           am=jp[i-1]-i;
           if(am>0 && hc[am]==0)
           {
            hc[am]=1;
            jp[i]=am;
           }
           else
           {
            am=jp[i-1]+i;
            hc[am]=1;
            jp[i]=am;
           }
        }
    }
    while(1)
    {
        scanf("%d",&n);
        if(n==-1)
            break;
        printf("%d\n",jp[n]);
    }
    return 0;
}
