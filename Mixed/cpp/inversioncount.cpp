#include<iostream>
#define x 200100
using namespace std;
long long int mergehc(int a[],int beg,int mid,int last)
{
    int temp[x],i,j,k;
    long long int counthc=0;
    for(i=beg,j=mid+1,k=beg;i<=mid&&j<=last;k++)
    {
        if(a[i]<=a[j])
        {
            temp[k]=a[i];
            i++;
        }
        else
        {
            temp[k]=a[j];
            j++;
            counthc+=(mid-i+1);
        }
    }
    if(i>mid)
    {
        for(;j<=last;j++)
        {
            temp[k]=a[j];
            k++;
        }
    }
    else if(j>last)
    {
        for(;i<=mid;i++)
        {
            temp[k]=a[i];
            k++;
        }
    }
    for(i=beg;i<=last;i++)
    {
        a[i]=temp[i];
    }
    return counthc;
}
long long int sorthc(int a[],int beg,int last)
{
    if(beg<last)
    {
    int mid;
    mid=(beg+last)/2;
    long long int p= sorthc(a,beg,mid);
    long long int q= sorthc(a,mid+1,last);
    long long int r= mergehc(a,beg,mid,last);
    return p+q+r;
    }
    return 0;
}
int main()
{
    int i,n,t,a[x];
    cin >>t;
    while(t--)
    {
      cin >>n;
      for(i=0;i<n;i++)
      {
        cin>>a[i];
      }
      cout << sorthc(a,0,n-1)<<endl;
    }
    return 0;
}
