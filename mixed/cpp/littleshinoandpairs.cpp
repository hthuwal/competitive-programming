#include <cstdio>
#define N 100005
int a[N];
int question(int n)
{
    int ans=0;
    int max_uptill_now=-1;
    for(int i=0;i<n-1;i++)
    {
        if(a[i+1]>a[i])
            ans++;
        else{
            ans+=a[i]-a[i+1];
        }
        // if(max_uptill_now<a[i])
        //     max_uptill_now=a[i];
    }
    return ans;yyyyyy
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("%d",question(n))
}