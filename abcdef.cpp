#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define x 110
#define y 1331000
int hc[y]={0},jp[y]={0},ss[x]={0};
int main()
{
    int n,i,j,k,l,ad,lo,hi;
    long int count;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&ss[i]);
    }
    for(i=0,l=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
               hc[l]=ss[i]*ss[j]+ss[k];
               l++;
            }
        }
    }
    ad=l;
    for(i=0,l=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                if(ss[k]!=0)
                {
                    jp[l]=(ss[i]+ss[j])*ss[k];
                    l++;
                }
            }
        }
    }
    sort(hc,&hc[ad]);
    sort(jp,&jp[l]);
    for(i=0,count=0;i<ad;i++)
    {
        lo=lower_bound(jp,&jp[l],hc[i])-jp;
        hi=upper_bound(jp,&jp[l],hc[i])-jp;
        count+=(hi-lo);
    }
    printf("%ld\n",count);
    return 0;
}
