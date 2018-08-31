	#include <cstdio>
	#define lli long long int

	lli coeff[300007];

	int main()
	{
		int n;
		scanf("%d",&n);
		lli highest_non_zero_coeff = -1;
		int index  = -1;
		
		for (int i = 0; i < n+1; ++i)
		{
			scanf("%lld",&coeff[i]);

			if(coeff[i] != 0)
			{
				highest_non_zero_coeff = coeff[i];		
				index = i;
			}
		}

		/*All coefficients are 0 then f(x) = 0*/
		if(index==-1)
		{
			printf("0 0");
		}
		else
		{
			/* sgn(f(superBig)) */
			if(highest_non_zero_coeff>0)
				printf("1 ");
			else 
				printf("-1 ");

			/* sgn(f(-superBig)) */
			if(index%2==1)
			{
				if(highest_non_zero_coeff>0)
					printf("-1");
				else 
					printf("1");
			}
			else
			{
				if(highest_non_zero_coeff>0)
					printf("1");
				else 
					printf("-1");	
			}
		}
	}