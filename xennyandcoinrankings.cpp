#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    long long int t,u,v;
    for(scanf("%lld",&t);t--;)
    {
        scanf("%lld %lld",&u,&v);
        v = v+u; // (0,l) start of the lldiagonal line containing (u,v)
        v = 1+(v)*(v+1)/2;
        v = v+u;
        printf("%lld\n",v);
    }
}