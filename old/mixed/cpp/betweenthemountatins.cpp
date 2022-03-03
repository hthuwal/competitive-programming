#include<iostream>
#include<algorithm>
#include<cmath>
#define x 1100
using namespace std;
void merge(int a[],int min, int mid, int max);
void mergesort(int a[],int min,int max)
{
    if(min<max)
    {
        int mid=(min+max)/2;
        mergesort(a, min, mid);
        mergesort(a, mid+1, max);
        merge(a, min, mid, max);
    }
}
void merge(int a[],int min, int mid, int max)
{
    int temp[x];
    int k=min,i,j;
    for(i=min,j=mid+1;i<=mid&&j<=max;)
    {
        if(a[i]<=a[j])
        {
            temp[k]=a[i];
            k++;
            i++;
        }
        else
        {
            temp[k]=a[j];
            k++;
            j++;
        }
    }
    while(i<=mid)
    {
        temp[k]=a[i];
        k++;
        i++;
    }
    while(j<=max)
    {
        temp[k]=a[j];
        k++;
        j++;
    }
    for(i=min;i<=max;i++)
    {
        a[i]=temp[i];
    }
}
int main()
{
    int a[x],b[x],diff,i,j,n,t,m;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        cin>>m;
        for(i=0;i<m;i++)
        {
            cin>>b[i];
        }
        mergesort(a,0,n-1);
        mergesort(b,0,m-1);
        diff=1000006;
        i=0;j=0;
        while(i<n&&j<m)
        {
            diff = min(diff,abs(a[i]-b[j]));
            if(a[i]<b[j])
            {
                i++;
            }
            else
                j++;

        }
        cout<<diff<<endl;
        }
        return 0;
}

