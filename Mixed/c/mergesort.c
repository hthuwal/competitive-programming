#include<stdio.h>
#define MAX 200015
long long merge1(long long a[], long long min, long long mid, long long  max)
{
    long long int temp[MAX], i,j,k, l,count=0;
    i=min;
    j=mid+1;
    for(k=min;i <= mid && j<=max; k++)
    {
        if(a[i] <= a[j])
        {
            temp[k] = a[i];
            i++;
        }
        else
        {
            temp[k] = a[j];
            j++;
            count+=mid-i;
        }
    }
    if(i>mid)
    {
        for(l=j; l<=max; l++)
        {
            temp[k] = a[l];
            k++;
        }
    }
    else
    {
        for(l=i; l<=mid; l++)
        {
            temp[k] = a[l];
            k++;
        }
    }
    for(l=min; l<=max; l++)
    {
        a[l] = temp[l];
    }
    return count;
}

long long sort1(long long  a[], long long min , long long max)
{
    long long mid,p,q,r;
    if(min < max)
    {
        mid = (min+max)/2;
        p=sort1(a, min, mid);
        q=sort1(a, mid+1, max);
        r=merge1(a, min, mid, max);
        return p+q+r;
    }
}
int main()
{
        long long int t,n,i,a[MAX];
        scanf("%lld",&t);
        while(t--)
        {
            scanf("%lld",&n);
            for(i=0;i<n;i++)
            {
                scanf("%lld",&a[i]);
            }
            printf("%lld\n",sort1(a,0,n-1));
        }
}
