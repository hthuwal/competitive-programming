/**"Notice that LCAT(u, v) is the closest node from the root 
encountered between the visits of u and v during a depth 
first search of T. So, we can consider all nodes between 
any two indices of u and v in the Euler Tour of the tree 
and then find the node situated on the smallest level 
between them. For this, we must build three arrays:**/
#include <cstdio>
#include <cmath>
#define N 10100
#define log2N 14
int lookup[N][log2N];
void preprocess(int arr[],int n)
{
    for(int i=0;i<n;i++)
        lookup[i][0]=i;
    for(int j=1;(1<<j)<=n;j++)
    {
        for(int i=0;i+(1<<j)-1<n;i++)
        {
            if(arr[lookup[i][j-1]] <
               arr[lookup[i+(1<<(j-1))-1][j-1]])
               lookup[i][j]=lookup[i][j-1];
            else
                lookup[i][j]=lookup[i+(1<<(j-1))][j-1];
        }
    }
}
int RMQ(int arr[],int L,int R)
{
    int j = (int)log2(R-L+1);
    if(arr[lookup[L][j]] < 
       arr[lookup[R-(1<<j)+1][j]])
       return arr[lookup[L][j]];
    else
       return arr[lookup[R-(1<<j)+1][j]];
}

int main()
{
    int arr[]={1,-1,4,0,4,3};
    preprocess(arr,6);
    printf("%d\n",RMQ(arr,0,5));
}