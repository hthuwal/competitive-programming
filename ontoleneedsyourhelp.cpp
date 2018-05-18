#include<cstdio>
using namespace std;
int main()
{
    int ans,n,i,x;
    scanf("%d",&n);
    ans=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        ans=ans^x;
    }
    printf("%d",ans);
    return 0;
}
