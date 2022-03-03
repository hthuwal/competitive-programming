#include<iostream>
#include<cstdio>
using namespace std;
class mylove
{
    public:
        int fun;
        int cost;
};
mylove jyoti(int w,int wt[],int val[],int n)
{
    mylove jp,x,y;
    if(n==0||w==0)
    {
        jp.cost=0;
        jp.fun=0;
        return jp;
    }
    if(wt[n-1]>w)
        return jyoti(w,wt,val,n-1);
    else
    {
        x=jyoti(w-wt[n-1],wt,val,n-1);
        x.cost+=wt[n-1];
        x.fun+=val[n-1];
        y=jyoti(w,wt,val,n-1);
        if(x.fun>=y.fun)
            return x;
        else
            return y;
    }

}
int main()
{
    int hc[100],jp[100],i,budget,n;
    while(1)
    {
        cin>>budget>>n;
        if(budget==0&&n==0)
            break;
        else
        {
            for(i=0;i<n;i++)
            {
                cin>>hc[i]>>jp[i];
            }
        }
        cout<<jyoti(budget,hc,jp,n).cost<<" "<<jyoti(budget,hc,jp,n).fun<<endl;
    }
    return 0;
}
