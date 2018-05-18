#include<cstdio>
#include<iostream>
using namespace std;
int ans[2005][2005];
int mylove(int hc[],int n)
{
    int i,j,l;
    for(i=0;i<n;i++)
    {
        ans[i][i]=hc[i]*n;
    }
    for(l=0;l<n-1;l++)
    {
        for(i=0;i<n-1;i++)
        {
            j=i+l+1;
            if(j==n)
                break;
            ans[i][j]=max(hc[i]*(n-j+i)+ans[i+1][j],hc[j]*(n-j+i)+ans[i][j-1]);
        }
    }
    return ans[0][n-1];
}
int main()
{
    int jp[2005],n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&jp[i]);
    printf("%d",mylove(jp,n));
    return 0;
}
