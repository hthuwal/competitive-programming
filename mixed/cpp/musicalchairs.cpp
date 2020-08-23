#include <cstdio>

int main()
{
	int n,k;
	while(1)
	{
		scanf("%d %d",&n,&k);
		if(n==0 || k==0)
			break;
		else
		{
			int ans = 1;
			for(int i=2;i<=n;i++)
			{
				ans = (ans + k - 1)%i + 1;
			}
			printf("%d %d %d\n", n,k,ans);
		}
	}	
}