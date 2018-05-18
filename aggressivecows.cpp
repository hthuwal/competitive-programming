#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[100005],cow;
bool check(int x)
{
    int hc=a[0];
    int c=cow-1;
    for(int i=1;i<n;i++)
        if(hc+x<=a[i])
        {
            c--;
            hc=a[i];
        }
    if(c<=0)
        return true;
    else
        return false;
}
int main()
{
    int t,i,p,q;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&cow);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        p=0;
        q=1000000000;
        while(q-p>1)
        {
            int mid=(p+q)/2;
            if(check(mid))
                p=mid;
            else
                q=mid;
        }
        if(check(q))
            printf("%d\n",q);
        else
            printf("%d\n",p);
    }
    return 0;
}
