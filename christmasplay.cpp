#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
int main()
{
    int hc[22000],dif,temp,t,n,k,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        for(i=0;i<n;i++)
        {
            scanf("%d",&hc[i]);
        }
        qsort(hc,n,sizeof(int),compare);
        for(i=0,dif=1000000000;;i++)
        {
            j=i+k-1;
            if(j>=n)
                break;
            temp=hc[j]-hc[i];
            if(temp<dif)
                dif=temp;
        }
        printf("%d\n",dif);
    }

}
