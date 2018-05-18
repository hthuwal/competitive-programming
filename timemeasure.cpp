#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	float diff = 1.0/120;
	float hc[13][61],jp,x,y;
	int i,j,t;
	for(i=0;i<=11;i++)
	{
		for(j=0;j<=59;j++)
		{
			y=6.0*j;
			x=i*30.0+(y/12.0);
			hc[i][j]=fabs(y-x);	
			if(hc[i][j]>180)
				hc[i][j]=360-hc[i][j];
		}
	}
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%f",&jp);
		for(i=0;i<=11;i++)
		{
			for(j=0;j<=59;j++)
			{
				if(fabs(hc[i][j]-jp)<diff)
				{
					if(i<10)
					{
						printf("0%d:",i);
					}
					else
					{
						printf("%d:",i);
					}
					if(j<10)
					{
						printf("0%d",j);
					}
					else
					{
						printf("%d",j);
					}
					printf("\n");
				}
			}
		}
	}
}