#include<iostream>
using namespace std;
static int harish(int v[],int w[],int W,int n)
{
 int sol[n],mysol[n],M[W+1],i,myfinalsol,c;
 M[0]=0;
 for(c=1;c<=W;c++)
 {
    for(i=0;i<n;i++)
    {
        if(c>=w[i])
            sol[i]=M[c-w[i]];
        else
            sol[i]=0;
    }
    for(i=0;i<n;i++)
    {
        if(c>=w[i])
            mysol[i]=sol[i]+v[i];
        else
            mysol[i]=0;
    }
    M[c]=mysol[0];
    for(i=1;i<n;i++)
        if(mysol[i]>M[c])
            M[c]=mysol[i];
 }
 return M[W];
}
