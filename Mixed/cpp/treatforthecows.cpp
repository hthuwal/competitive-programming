#include<cstdio>
using namespace std;
int x=1;
int jyoti[2005][2005]={0};
int mylove(int hc[],int a,int b,int y)
{
    int p,q;
    if(a<=b)
    {
        p=hc[a]*y+mylove(hc,a+1,b,y+1);
        q=hc[b]*y+mylove(hc,a,b-1,y+1);
        if(p>=q)
            return p;
        else
            return q;
    }
    else
        return 0;
}
int main()
{
    int jp[2005],n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&jp[i]);
    printf("%d",mylove(jp,0,n-1,x));
    return 0;
}
int jp(int hc[])
{
    int a[n][n];
    for(i=0;i<n;i++)
    {
        a[i][i]=hc[i]*n;
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            a[i][j]=max(hc[i]*(n-i)+a[i+1][j],hc[j]*(n-i)+a[i][j-1]);
        }
    }
}
