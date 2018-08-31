#include <cstdio>
#include <cstdlib>
int gcd(int a,int b)
{
	if(a==0 && b==0)
		return 1;
	int t;
	while(b!=0)
	{
		// printf("a:%d b:%d\n",a,b);
		t=a%b;
		a=b;
		b=t;
	}
	return a;
}
int main()
{
	freopen("in.txt","r",stdin);	
	int t,a,b,c;
	for(scanf("%d",&t);t--;)
	{
		scanf("%d %d",&a,&b);
		c=gcd(a,b);
		a=a/c;b=b/c;
		printf("%d\n",abs(a-b));
	}
}