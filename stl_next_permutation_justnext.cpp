#include <cstdio>
#include <algorithm>
using namespace std;
int arr[1111111];
int temp[1111111];
int main()
{
    freopen("in.txt","r",stdin);
    int t,n;
    for(scanf("%d",&t);t--;)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d ",&arr[i]);
            temp[i]=arr[i];
        }
        // printf("\n");
        if(next_permutation(arr,arr+n)==false)
            printf("-1\n");
        else
        {
            for(int i=0;i<n;i++)
                printf("%d",arr[i]);
            printf("\n");
        }
        
    }
}