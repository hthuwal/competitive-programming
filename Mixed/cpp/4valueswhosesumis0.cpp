#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define x 4100
#define y 16810000
int a[x],b[x],c[x],d[x];
int p[y],q[y];
int main()
{
    int t,i,k,j,lo,hi;
    long long int count;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
    }
    for(i=0,k=0;i<t;i++)
    {
        for(j=0;j<t;j++)
        {
            p[k]=a[i]+b[j];
            q[k]=c[i]+d[j];
            k++;
        }
    }
    sort(p,&p[k]);sort(q,&q[k]);
    for(i=0,count=0;i<k;i++)
    {
        lo=lower_bound(q,&q[k],-p[i])-q;
        hi=upper_bound(q,&q[k],-p[i])-q;
        count+=(hi-lo);
    }
    printf("%lld",count);
}
