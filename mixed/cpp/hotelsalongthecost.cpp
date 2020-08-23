#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    long int n,m,i,j,sum,maxsum,hc[350000];
    scanf("%ld %ld",&n,&m);
    for(i=0,j=0;i<n;i++)
    {
        scanf("%ld",&hc[i]);
    }
    i=0;j=0;sum=0;maxsum=0;
    while(j<n)
    {
        if(i<n)
            sum=sum+hc[i];
        if(sum>maxsum && sum<=m)
        {
            maxsum=sum;
        }
        else if(sum>m && i<n)
        {
            sum=sum-hc[j]-hc[i];
            i--;
            j++;
        }
        else if(i > n)
        {
            sum=sum-hc[j];
            j++;
        }
        i++;
    }
    printf("%ld",maxsum);
    return 0;
}
