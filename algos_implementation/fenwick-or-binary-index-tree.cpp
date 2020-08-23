/*           
                {           a[x],                  if x is odd
BIT[x] =                    a[1] + ... + a[x],     if x is power of 2
                }
To generalize this every index i in the BIT[] array stores the
cumulative sum from the index i - (1<<r) + 1 to i (both inclusive), where 
r represents the last set bit in the index i*/

#include <cstdio>
#define N 100
int bit[N];

/*
update(x,y) => add y to index x;
when an update() operation is performed on index x we update all the indices 
of BIT[] which cover index x.
suppose x = 13
x=13 covered by 13 14 and 16 as shown: 
13 (13)
14 (13 to 14)
15 (15) 
16 (1 to 16)

therefore
update x = 13 or 1101 update bit[13] x=x+x&(-x) => x=13+1
update x = 14 or 1110 update bit[14] x=x+x&(-x) => x=14+2
update x = 16 or 10000 update bit[16] x=x+x&(-x) => x=16+16 > n
*/
void update(int x,int data,int n)
{
    for(;x<=n; x+=(x&-x))
        bit[x]+=data;
}

int getsum(int x,int n)
{
    int sum=0;
    for(;x>=1;x-=(x&-x))
        sum+=bit[x];
    return sum;
}
int main(){
    int n,x;
    int a[N];
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
        bit[i]=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        update(i,a[i],n);
    }
    scanf("%d",&x);
    printf("sum up to %d is %d\n",x,getsum(x,n));
    update(4,5,n);
    printf("sum up to %d after updatint index 4 to 5 is %d\n",x,getsum(x,n));
}