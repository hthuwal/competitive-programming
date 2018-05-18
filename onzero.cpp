#include <cstdio>
#include <queue>
using namespace std;
// int q[111111111];
int arr[111111111];
bool hash[22222];
char spoj[111111111];
queue<int> q;
int hc(int n)
{
    int f=0,r=0,ans=-1,i,top;
    // q[r++]=1;
    q.push(1);
    
    arr[1]=1;
    while(1)
    {
        // i = q[f++];
        i = q.front();q.pop();
        top = arr[i]%n;
        // printf("%d\n",top);        
        if(top%n==0)
        {
            ans=i;
            break;
        }
        else if(!hash[top%n])
        {
            hash[top%n]=true;
            int left = i<<1;
            int right = left|1;
            // q[r++]=left;
            // q[r++]=right;
            q.push(left);
            q.push(right);
            arr[left]=(top*10)%n;
            arr[right]=(arr[left]+1)%n; 
        }
    }
    int ptr=0;
    // printf("%d\n",ans);
    while(ans!=0)
    {
        spoj[ptr++]='0'+ans%2;
        ans=ans/2;
    }
    ptr--;
    for(int i=ptr;i>=0;i--)
        printf("%c",spoj[i]);
    printf("\n");
}
int main(){
    freopen("in.txt","r",stdin);
    int t,x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&x);
        for(int i=0;i<x;i++)
            hash[i]=false;
        hc(x);
    }

}
