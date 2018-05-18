#include <cstdio>
using namespace std;
int hc[2100]={0};
int main()
{
    int t,n;
    freopen("in.txt","r",stdin);
    hc[1]=0;
    for(int i=2;i<2100;i++)
    {
        hc[i]=hc[i-1];
        for(int j=1;j<i;j++)
        {
            if((i^j)<=i)
                hc[i]++;
        }
    }
    // for(scanf("%d",&t);t--;)
    // {
    //     scanf("%d",&n);
    //     printf("%d\n",hc[n]);
    // }
    for(int i=0;i<45;i++)
        printf("%d ",hc[i]);
}