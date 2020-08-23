#include <cstdio>
#include <algorithm>

#define N 311111
#define blocksize 558
using namespace std;

typedef struct trio{
    int l,r,index;
} trio;

int arr[N];
trio queries[211111];
int answer[211111];
int hash[1000100];

int ans=0;

bool comp(trio a,trio b)
{
    if(a.l/blocksize != b.l/blocksize)
        return a.l/blocksize<b.l/blocksize;
    return a.r<b.r; 
}

void add(int pos)
{
    hash[arr[pos]]++;
    if(hash[arr[pos]]==1)
        ans++;
}
void remove(int pos)
{
    hash[arr[pos]]--;
    if(hash[arr[pos]]==0)
        ans--;
}
int main()
{
    freopen("in.txt","r",stdin);
    int n,q;
    scanf("%d",&n);
    for(int i=0;i<1000100;i++)
        hash[i]=0;
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        queries[i].index=i;
        scanf("%d %d",&queries[i].l,&queries[i].r);
        queries[i].l--;
        queries[i].r--;

    }
    sort(queries,queries+q,comp);
    int curr_l=0,curr_r=0;
    for(int i=0;i<q;i++)
    {
        int l=queries[i].l,r=queries[i].r;
        
        while(curr_r<=r)
        {
            add(curr_r);
            curr_r++;
        }
        while(curr_l>l)
        {
            add(curr_l-1);
            curr_l--;
        }
        while(curr_r > r+1)
        {
            remove(curr_r-1);
            curr_r--;
        }
        while(curr_l < l)
        {
            remove(curr_l);
            curr_l++;
        }
        answer[queries[i].index]=ans;
    }
    for(int i=0;i<q;i++)
    {
        printf("%d\n",answer[i]);
    }
}
