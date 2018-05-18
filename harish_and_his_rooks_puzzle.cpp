#include <cstdio>

int main()
{
	int t;
	char puz[10][10];
	for(scanf("%d",&t);t--;)
	{
		for(int i=0;i<8;i++)
			scanf("%s",puz[i]);

		int row[8]={0};
		int col[8]={0};

		for(int i=0;i<8;i++)
			for(int j=0;j<8;j++)
			{
				if(puz[i][j]=='R')
				{
					row[i]++;
					col[j]++;
				}
			}

		bool ans = false;
		for(int i=0;i<8;i++)
		{
			if(row[i]==1 && col[i]==1)
				ans = true;
			else
			{
				ans = false;
				break;
			}
		}
		if(ans)
			printf("YES\n");
		else
			printf("NO\n");
	}
}