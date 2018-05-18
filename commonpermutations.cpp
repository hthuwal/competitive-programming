#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char l[1100][1100];
void merge(char a[],int min, int mid, int max);
void mergesort(char a[],int min,int max)
{
    if(min<max)
    {
        int mid=(min+max)/2;
        mergesort(a, min, mid);
        mergesort(a, mid+1, max);
        merge(a, min, mid, max);
    }
}
void merge(char a[],int min, int mid, int max)
{
    char temp[1100];
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
void lcs(char a[],char b[],int n, int m)
{
    int i,j,x,k;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                l[i][j]=0;
            }
            else if(a[i-1]==b[j-1])
            {
                l[i][j]=1+l[i-1][j-1];
            }
            else
            {
                l[i][j]=max(l[i-1][j],l[i][j-1]);
            }
        }
    }
    x = l[n][m];
    k=x;
    char hc[x+1];
    hc[x]='\0';
    i=n;
    j=m;
    while(i>0 && j>0)
    {
        if(a[i-1]==b[j-1])
        {
            hc[x-1]=a[i-1];
            i--;j--;x--;
        }
        else if(l[i-1][j]>l[i][j-1])
            i--;
        else
            j--;
    }
    mergesort(hc,0,k-1);
    cout<<hc<<endl;
}
int main()
{
    char hc[1100],jp[1100];
    int n,m;
    while(scanf("%s",hc)!=EOF)
    {
        scanf("%s",jp);
        n=strlen(hc);
        m=strlen(jp);
        lcs(hc,jp,n,m);
    }
}

