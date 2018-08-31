#include <cstdio>
#include <cmath>
#include <climits>
#define N 101000
#define LN 17
int arr[N];
int st[6*N];

void create(int ti,int l,int r)
{
    if(l==r)
        st[ti]=arr[l];
    else
    {
        int mid = (l+r)>>1;
        int left = ti<<1;
        int right = left | 1;
        create(left,l,mid);
        create(right,mid+1,r);
        st[ti]= st[left]<st[right]?st[left]:st[right];
    }
}
int getmin(int ti,int l,int r,int ql,int qr)
{
    if(l>qr || r<ql)
        return INT_MAX;
    if(l>=ql && r<=qr)
        return st[ti];
    int mid = (l+r)>>1;
    int c1 = ti<<1;
    int c2 = c1|1;
    int left_min = getmin(c1,l,mid,ql,qr);
    int right_min = getmin(c2,mid+1,r,ql,qr);
    return left_min < right_min ? left_min : right_min;
    
}
int main()
{
    freopen("in.txt","r",stdin);
    int t,n,q,a,b;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        printf("Scenario #%d:\n",i);
        scanf("%d %d",&n,&q);
        for(int j=0;j<n;j++)
            scanf("%d",&arr[j]);
        create(1,0,n-1);
        while(q--)
        {
            scanf("%d %d",&a,&b);
            printf("%d\n",getmin(1,0,n-1,--a,--b));
        }
    }
}