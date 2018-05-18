#include <cstdio>
#include <map>
#include <iostream>
using namespace std;
map<string,int> hc;
#define N 33333
string shabd[N];
int lafz[N];
int count=0;
void init()
{
    count=0;
    hc.empty();
}
void merge(int l,int mid,int h)
{
    int i=l,j=mid+1;
    int temp[h-l+1],k=0;
    for(;i<=mid && j<=h;)
    {
        if(lafz[i]>lafz[j])
        {
            count+=(mid-i+1);
            temp[k++]=lafz[j];
            j++;
        }
        else{
            temp[k++]=lafz[i];
            i++;
        }
    }
    while(i<=mid)
        temp[k++]=lafz[i++];

    while(j<=h)
        temp[k++]=lafz[j++];
    for(int i=0;i<k;i++)
    {
        lafz[l+i]=temp[i];
    }
}
void mergesort(int l,int h)
{
    if(l<h)
    {
        int mid = (l+h)>>1;
        mergesort(l,mid);
        mergesort(mid+1,h);
        merge(l,mid,h);
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    int t,n;
    for(scanf("%d",&t);t--;)
    {
        init();
        scanf("%d",&n);
        string aditi;
        for(int i=0;i<n;i++)
            cin>>shabd[i];
        for(int i=0;i<n;i++)
        {
            cin>>aditi;
            hc[aditi]=i;
        }
        for(int i=0;i<n;i++)
            lafz[i]=hc[shabd[i]];
        mergesort(0,n-1);
        printf("%d\n",count);
    }
}