#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
long long int create(long long int a[],long long int sl,long long int sh,long long int tree[],long long int si)
{
	if(sl==sh)
	{
		tree[si]=a[sl]*a[sl];
		return tree[si];
	}
	else
	{
		long long int mid=(sl+sh)/2;
		tree[si]=create(a,sl,mid,tree,2*si)+create(a,mid+1,sh,tree,2*si+1);
		return tree[si];
	}
}
long long int getsum(long long int tree[],long long int sl,long long int sh,long long int si,long long int ql,long long int qh)
{
	if(ql<=sl && qh>=sh)
		return tree[si];
	if(sh<ql || sl>qh)
		return 0;
	long long int mid=(sl+sh)/2;
	return getsum(tree,sl,mid,2*si,ql,qh)+getsum(tree,mid+1,sh,2*si+1,ql,qh);
}
void update0(long long int tree[],long long int sl,long long int sh,long long int si,long long int i,long long int p,long long int x)
{
	if(i<sl||i>sh)
		return;
	tree[si]+=((x*x)-(p*p));
	if(sl!=sh)
	{
		long long int mid = (sl+sh)/2;
		update0(tree,sl,mid,2*si,i,p,x);
		update0(tree,mid+1,sh,2*si+1,i,p,x);
	}
}
void update1(long long int tree[],long long int sl,long long int sh,long long int si,long long int i,long long int p,long long int x)
{
	if(i<sl||i>sh)
		return;
	tree[si]+=(((x+p)*(x+p))-(p*p));
	if(sl!=sh)
	{
		long long int mid = (sl+sh)/2;
		update1(tree,sl,mid,2*si,i,p,x);
		update1(tree,mid+1,sh,2*si+1,i,p,x);	
	}
}
int main()
{
	long long int tree[270000];
	long long int a[110000];
	long long int p,t,i,n,q,k,j,x,u,w;
	scanf("%lld",&t);
	w=1;
	while(w<=t)
	{
		printf("Case %lld:\n",w);
		scanf("%lld %lld",&n,&q);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		
		memset(tree,-1,sizeof(tree));
		
		create(a,0,n-1,tree,1);
		
		for(k=0;k<q;k++)
		{
			scanf("%lld",&p);
			if(p==2)
			{
				scanf("%lld %lld",&i,&j);
				i--;
				j--;
				printf("%lld\n",getsum(tree,0,n-1,1,i,j));
			}
			else
			{
				scanf("%lld %lld %lld",&i,&j,&x);
				i--;
				j--;
				for(;i<=j;i++)
				{
					u=a[i];
					if(p==0)
					{
						a[i]=x;
						update0(tree,0,n-1,1,i,u,x);
					}
					else if(p==1)
					{
						a[i]+=x;
						update1(tree,0,n-1,1,i,u,x);
					}
				}

			}
		}
		w++;
	}	
}