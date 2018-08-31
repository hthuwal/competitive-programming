#include <cstdio>
#include <algorithm>
int main()
{
    int t,n,count,flag=0;
    char a[11000];
    for(scanf("%d",&t);t--;)
    {
        count=0;
        flag=0;
        scanf("%d",&n);
        scanf("%s",a);
        for(int i=0;i<n;i++)
        {
            if(a[i]>='0' && a[i]<='9' && flag==0)
            {
                flag=1;
                count++;
            }
            else if(a[i]<'0' || a[i]>'9')
                flag=0;

        }
        printf("%d\n",count);
    }
}