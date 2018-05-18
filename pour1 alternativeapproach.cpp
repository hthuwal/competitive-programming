#include <cstdio>


int main()
{
	freopen("in.txt","r",stdin);
	int t,a,b,c;
	for(scanf("%d",&t);t--;)
	{
		scanf("%d %d %d",&a,&b,&c);
		if( c>a && c>b)
			printf("-1\n");
		else if(gcd(a,b,c)==-1)
			printf("-1\n");
		else{
			// printf("Hi");
			int ans1 = simulate(a,b,c);
			int ans2 = simulate(b,a,c);
			ans1 = ans1< ans2?ans1:ans2;
			printf("%d\n",ans1);
		}
		
	}
	

}