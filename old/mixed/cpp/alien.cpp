#include <iostream>
#include <cstdio>
using namespace std;
void ans(int a[],int n,int bound)
{
	int t1=0,a1=0,a2=0,s=0,e=0;
	while(1)
	{

		if(e-s>a2 && t1<=bound){
			a1=t1;
			a2=e-s;
		}
		else if(e-s==a2 && t1<a1 && t1<=bound)
		{
			a1=t1;
		}
		if(t1>bound && s<n)
		{
			t1-=a[s];
			s+=1;
		}
		else if(e<n)
		{
			t1+=a[e];
			e+=1;
		}
		else
		{
			break;
		}
	}
	printf("%d %d\n",a1,a2);
}
int main()
{
	freopen("in.txt","r",stdin);
	int t; scanf("%d",&t);
	while(t--)
	{
		int at,bt; scanf("%d %d",&at,&bt);
		int hc[at];
		for(int i=0;i<at;i++) scanf("%d",&hc[i]);
		ans(hc,at,bt);
	}

}