#include<iostream>
#include<cstdio>
using namespace std;

struct hc
{
    int x;
    int y;
};

static int harish(int v[],int w[],int W,int n)
{
 hc sol[n],mysol[n],M[W+1];
 int i,c,flag;
 M[0].x=0;
 M[0].y=0;
 for(c=1;c<=W;c++)
 {
    for(i=0;i<n;i++)
    {
        if(c>=w[i])
            sol[i]=M[c-w[i]];
        else
            {
                sol[i].x=0;
                sol[i].y=0;
            }
    }
    for(i=0;i<n;i++)
    {
        if(c>=w[i])
            {
                mysol[i].x=sol[i].x+v[i];
                mysol[i].y=sol[i].y+w[i];
            }
        else
            {
                mysol[i].x=0;
                mysol[i].y=0;
            }
    }

    for(i=0,flag=0;i<n;i++)
    {    if(mysol[i].y==c)
            {
                M[c]=mysol[i];
                flag=1;
                break;
            }
    }
    if(flag==0)
    {
        M[c].x=0;
        M[c].y=0;
    }
    else
    {
        for(;i<n;i++)
        {
            if(mysol[i].y==c&&mysol[i].x<M[c].x)
                M[c]=mysol[i];
        }
    }
 }
 return M[W].x;
}

int main()
{
    int t,a,ans,b,n,i,v[555],w[555];
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        a=b-a;
        cin>>n;
        for(i=0;i<n;i++)
        {
        cin>>v[i]>>w[i];
        }
    ans=harish(v,w,a,n);
    if(ans==0)
        cout<<"This is impossible."<<endl;
    else
        cout<<"The minimum amount of money in the piggy-bank is "<<ans<<"."<<endl;
    }
    return 0;
}


