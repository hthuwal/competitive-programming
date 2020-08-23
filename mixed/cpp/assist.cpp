#include <cstdio>
#include <vector>
using namespace std;
#define N 35000
vector<int> a(N,0);
void print()
{
    for(int i=0;i<25;i++)
        printf("%d ",a[i]);
    printf("\n");
}
void hc()
{
    for(int i=0;i<N;i++)
        a[i]=i;
    for(int i=2;i<a.size();i++)
    {
        // print();
        for(int j=i+a[i];j<a.size();j+=(a[i]-1))
        {
            a.erase(a.begin()+j);
        }
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    hc();
    int t;
    // printf("%ld",a.size());
    // for(int i=0;i<21;i++)
    // {
    //     printf("%d ",a[i]);
    // }
    while(1)
    {
        scanf("%d",&t);
        if(t==0)
            break;
        printf("%d\n",a[t+1]);
    }
}