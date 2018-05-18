#include <cstdio>

int gcd(int a,int b,int c)
{
	int temp;
	while(b!=0)
	{
		temp=b;
		b=a%b;
		a=temp;
	}
	if(c%a==0)
		return 1;
	else
		return -1;
}

/*
You must simulate by doing "pouring action" only in one jug and "discharging action" only in the opposite jug.

(1)pour in a, discharge in b: if a is empty pour a full, if b is full the discharge and make b empty. Otherwise, transfer water from a to b. Each of those three condition is a step & can happen only once at a time.

(2)pour in b, discharge in a: if b is empty pour it full, if a is full make it empty. Otherwise, transfer water from b to a.

count total steps for (1) and (2), the minimum is the answer.

for (1) simulation can be:

*/
int simulate(int a,int b,int c)
{
	int x=0,y=0,count=0;
	while(x!=c && y!=c)
	{
		if(x==0)
			x=a;
		else if(y==b)
			y=0;
		else 
		{
			y=y+x;
			x=0;
			if(y>b)
			{
				x=y-b;
				y=b;
			}
		}
		count++;
	}
	return count;
}
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