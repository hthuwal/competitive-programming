#include <cstdio>
using namespace std;
int main()
{
    freopen("in.txt","r",stdin);
    int t,x;
    for(scanf("%d",&t);t--;)
    {
        scanf("%d",&x);
        if(x%2==0)
            printf("Thankyou Shaktiman\n");
        else
            printf("Sorry Shaktiman\n");
    }
}