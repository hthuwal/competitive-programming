#include<cstdio>
#include<map>
using namespace std;
int main()
{
    int t,n,a,i,flag;
    scanf("%d",&t);
    while(t--)
    {
        map<int,int> hc;
        scanf("%d",&n);
        for(i=0,flag=0;i<n;i++)
        {
            scanf("%d",&a);
            hc[a]+=1;
            if(hc[a]>(n/2)&&flag==0)
            {
                printf("YES %d\n\n",a);
                flag=1;
            }
        }
        if(flag==0)
            printf("NO\n\n");
    }
    return 0;
}
