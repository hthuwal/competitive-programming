#include <cstdio>
#include <cstring>
#define N 111111

int tree[3][6*N];
int lazy[6*N]={0};

void create(int ti, int sl, int sh)
{
	if(sl==sh)
	{
		tree[0][ti]=1;
		tree[1][ti]=tree[2][ti]=0;
	}
	else
	{
		int mid = (sl + sh)>>1;
		create(2*ti,sl, mid);
		create(2*ti+1, mid+1, sh);
		tree[0][ti] = tree[0][2*ti] + tree[0][2*ti+1];
		tree[1][ti]=tree[2][ti]=0;
	}
}
void beactive(int ti, int sl, int sh)
{
	if(lazy[ti]==1)
	{
		int x = tree[0][ti];
		tree[0][ti] = tree[2][ti];
		tree[2][ti] = tree[1][ti];
		tree[1][ti] = x; 
	}
	if (lazy[ti]==2)
	{
		int x = tree[0][ti];
		tree[0][ti] = tree[1][ti];
		tree[1][ti] = tree[2][ti];
		tree[2][ti] = x;
	}
	if( sl!=sh)
	{
		lazy[2*ti] = (lazy[ti] + lazy[2*ti])%3;
		lazy[2*ti + 1] = (lazy[ti] + lazy[2*ti + 1])%3;
	}
	lazy[ti] = 0;
}

void update(int ti, int sl, int sh, int i, int j)
{
	if(lazy[ti]) beactive(ti, sl, sh);

	if( sl > j || sh < i )
		return;

	if( sl >= i && sh <=j )
	{
		if( sl!=sh)
		{
			lazy[2*ti] = (1 + lazy[2*ti]) % 3;
			lazy[2*ti + 1] = (1 + lazy[2*ti + 1]) % 3;
		}

		int x = tree[0][ti];
		tree[0][ti] = tree[2][ti];
		tree[2][ti] = tree[1][ti];
		tree[1][ti] = x; 
		return ;
	}

	int mid = (sl + sh) >> 1;

	update(2*ti, sl, mid, i ,j);
	update(2*ti+1, mid+1, sh, i, j);

	tree[0][ti] = tree[0][2*ti] + tree[0][2*ti+1];
	tree[1][ti] = tree[1][2*ti] + tree[1][2*ti+1];
	tree[2][ti] = tree[2][2*ti] + tree[2][2*ti+1];
	
}

int getcount(int ti, int sl, int sh, int i ,int j)
{
	if(lazy[ti]) beactive(ti, sl, sh);

	if( sl > j || sh < i )
		return 0;

	if( sl >= i && sh <=j )
		return tree[0][ti];

	int mid = (sl+sh)>>1;

	return getcount(2*ti, sl, mid, i, j) + getcount(2*ti + 1, mid+1, sh, i, j);
}

int main()
{
	int a,b,c,n,q;
	scanf("%d",&n);

	create(1,0,n-1);

	for(scanf("%d",&q);q--;)
	{
		scanf("%d %d %d",&a,&b,&c);
		if(a==0)
			update(1,0,n-1,b,c);
		else
			printf("%d\n",getcount(1,0,n-1,b,c));
	}
}