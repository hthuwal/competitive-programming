#include <cstdio>
#define N 111111
int a[N];
int st[6*N];

void create(int ti,int l,int h)
{
    if(l==h)
    {
        st[ti]=1;
    }
    else
    {
        int mid = (l+h)>>1;
        int left = ti<<1;
        int right = left | 1;
        create(left,l,mid);
        create(right,mid+1,h);
        st[ti]=st[left]>st[right]?st[left]:st[right];
        if(a[mid]==a[mid+1])
        {
            int i = mid;
            int count=0;
            while(i>=l && a[i]==a[mid])
            {
                count++;
                i--;
            }
            i=mid+1;
            while(i<=h && a[i]==a[mid])
            {
                count++;
                i++;
            }
            if(count>st[ti])
                st[ti]=count;
        }
    }
}
int getans(int ti,int l,int r,int ql,int qr)
{
    if(qr < l || ql > r)
        return 0;
    if(ql <= l && qr >= r)
        return st[ti];
    else
    {   
        int mid = (l+r)>>1;
        int left = ti<<1;
        int right = left | 1;
        int ansl = getans(left,l,mid,ql,qr);
        int ansr = getans(right,mid+1,r,ql,qr);
        int ans=ansl>ansr?ansl:ansr;
        if(a[mid]==a[mid+1])
        {
            int i = mid;
            int count=0;
            while(i>=ql && i>=l && i<=qr && a[i]==a[mid])
            {
                count++;
                i--;
            }
            i=mid+1;
            while(i<=qr && i<=r && i>=ql && a[i]==a[mid])
            {
                count++;
                i++;
            }
            if(count>ans)
                ans=count;
        }
        return ans;
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    int n,q;
    //   printf("HI");
    while(1)
    {
        //   printf("HI");
        scanf("%d",&n);
        if(n==0)
            break;
        scanf("%d",&q);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        create(1,0,n-1);
        //   for(int i=0;i<30;i++)
        //     printf("%d ",st[i]);
        //   printf("\n");
        int ql,qh;
        for(int i=0;i<q;i++)
        {
            scanf("%d %d",&ql,&qh);
            printf("%d\n",getans(1,0,n-1,--ql,--qh));
        }
    }
}