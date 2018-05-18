//on observing such numbers one gets a pattern that the number forms an AP starting with 192 and with a common difference of 250//
#include<stdio.h>
int main()
{
    long long int k,t,ans;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&k);
        ans=192+(k-1)*250;
        printf("%lld\n",ans);
    }
    return 0;
}
