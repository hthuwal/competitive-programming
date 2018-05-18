#include<stdio.h>
int main()
{
    unsigned long long int n;
    scanf("%lld",&n);
    if(n<=1||((n&(n-1))==0))
        printf("TAK");
    else
        printf("NIE");
    return 0;
}
