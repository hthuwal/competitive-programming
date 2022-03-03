#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define N 11111
long long int a[N];
long long int b[N];
int main()
{
    freopen("in.txt","r",stdin);
    long long int n,avg;
    scanf("%lld",&n);
    avg=0;
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        avg+=a[i];
    }
    avg/=n;

    /**how far is everyone from avg**/
    for(int i=0;i<n;i++)
        a[i]=a[i]-avg;

    /**EVERYONE TRANSFERS HIS EXTRAS TO THE RIGHT**/
    b[0]=0;//suppose first person gets 0 from last person
    /*each person now transfers his extra to the person on the right
     b[i] stroes how much does ith needs to transfer to the right*/
    for(int i=1;i<=n-1;i++)
    {
        b[i]=b[i-1]+a[i-1];
    }
    sort(b,b+n);
    long long int median = -b[n/2];
    long long int ans=0;
    for(int i=0;i<n;i++)
        ans+=abs(b[i]+median);
    printf("%lld\n",ans);
}