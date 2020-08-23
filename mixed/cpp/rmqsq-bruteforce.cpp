#include <cstdio>
#include <climits>
int arr[101000];
int ans(int l,int r)
{
    int min = INT_MAX;
    for(int i=l;i<=r;i++)
        if(arr[i]<min)
            min=arr[i];
    
    return min;
}
int main()
{
    freopen("in.txt","r",stdin);
    int n,q,a,b;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<=1;j++)
    //         printf("%d ",lookup[i][j]);

    //     printf("\n");
    // }
    for(scanf("%d",&q);q--;)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",ans(a,b));
    }
}