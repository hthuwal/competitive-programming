#include <iostream>
#include <cstdio>
#include <vector>
#define vi vector<int>
using namespace std;
vi hc(int n)
{
    vi ans;
    if(n>=1)
        ans.push_back(1);
    if(n>=2)
        ans.push_back(2);
    if(n>=3)
        ans.push_back(4);
    n=n-3;
    for(int i=0;i<n;i++)
        ans.push_back(ans[2+i]+3);
    return ans;
}
int main()
{
    int t,n;
    vi x;
    for(scanf("%d",&t);t--;)
    {
        scanf("%d",&n);
        x = hc(n);
        for(int i=0;i<n;i++)
            printf("%d ",x[i]);
        printf("\n");
    }
}