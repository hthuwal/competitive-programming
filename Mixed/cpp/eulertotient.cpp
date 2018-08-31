#include<cstdio>
using namespace std;
int hc(int x)
{
    int i,result=x;
    for(i=2;i*i<=x;i++)
    {
        if(x%i==0)
            result -= result/i;
        while(x%i==0)
            x=x/i;
    }
    if(x>1)
        result -=result/x;
    return result;
}
int main()
{
    int t,num;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&num);
        printf("%d\n",hc(num));
    }
    return 0;
}
