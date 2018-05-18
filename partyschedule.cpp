#include<iostream>
using namespace std;
#define MAX 100005
void merge1(long long a[],long long b[], long long min, long long mid, long long  max)
{
    long long int temp[MAX],harish[MAX], i,j,k, l;
    i=min;
    j=mid+1;
    for(k=min;i <= mid && j<=max; k++)
    {
        if(a[i] > a[j])
        {
            temp[k] = a[i];
            harish[k] = b[i];
            i++;
        }
        else if(a[i]<a[j])
        {
            temp[k] = a[j];
            harish[k] = b [j];
            j++;
        }
        else
        {
            if(b[i]<=b[j])
            {
            temp[k] = a[i];
            harish[k] = b[i];
            i++;
            }
            else
            {
            temp[k] = a[j];
            harish[k] = b [j];
            j++;
            }
        }
    }
    if(i>mid)
    {
        for(l=j; l<=max; l++)
        {
            temp[k] = a[l];
            harish[k] = b[l];
            k++;
        }
    }
    else
    {
        for(l=i; l<=mid; l++)
        {
            temp[k] = a[l];
            harish[k] = b[l];
            k++;
        }
    }
    for(l=min; l<=max; l++)
    {
        a[l] = temp[l];
        b[l] = harish[l];
    }
}

void sort1(long long  a[],long long b[], long long min , long long max)
{
    long long mid;
    if(min < max)
    {
        mid = (min+max)/2;
        sort1(a,b, min, mid);
        sort1(a,b, mid+1, max);
        merge1(a,b, min, mid, max);
    }
}
int main()
{
    long long int hc[MAX],jp[MAX],budget,n,i,cost,fun;
    while(1)
    {
    cin>>budget>>n;
    if(budget==0&&n==0)
        break;
    else
    {
    for(i=0;i<n;i++)
    {
        cin>>hc[i]>>jp[i];
    }
    sort1(jp,hc,0,n-1);
    cout <<endl;
    for(i=0;i<n;i++)
    {
        cout<<hc[i]<<" "<<jp[i]<<endl;
    }
    for(i=0,cost=0,fun=0;i<n;i++)
    {
        if(cost+hc[i]>budget)
            continue;
        else
        {
            cost+=hc[i];
            fun+=jp[i];
        }
    }
    fort
    cout<<cost<<" "<<fun<<endl;
    }
    }
    return 0;
}
