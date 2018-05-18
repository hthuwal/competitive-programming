#include<iostream>
#include<cstdio>
using namespace std;
int a[60000];
int max(int x, int y)
{ return (y > x)? y : x; }
int maxSubArraySum(int l,int u)
{
   int max_so_far = a[l], i;
   int curr_max = a[l];

   for (i = l+1; i <= u; i++)
   {
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
   }
   return max_so_far;
}

int main(){
    int n,i,m,l,u;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%d %d",&l,&u);
        l--;u--;
        printf("%d\n",maxSubArraySum(l,u));
    }
}
