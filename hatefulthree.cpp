/*input
2
3
16
*/
#include <cstdio>
int lcm(int a,int b)
{
	int x=a,y=b;
	int temp;
	while(b>0)
	{
		temp=b;
		b=a%b;
		a=temp;
	}
	return (x*y)/a;
}
int main()
{
	int n,t;
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);
		n = lcm(n,lcm(n-1,n-2));
		printf("%d\n",n);
	}
}