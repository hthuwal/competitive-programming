#include <bits/stdc++.h>

typedef struct plus
{
	int cr, cc;
	int v[5];
} plus;

plus pluses[3000];

bool is_not_overlapped(plus a, plus b)
{
	if(a.cr == b.cr)
		return abs(a.cc - b.cc) >= 3;

	if(a.cc == b.cc)
		return abs(a.cr - b.cr) >= 3;

	return abs(a.cr - b.cr) >= 2 || abs(a.cc - b.cc) >=2;
}

int value(plus a, plus b)
{
	if (is_not_overlapped(a, b))
		return a.v[0] * b.v[0] + a.v[1] * b.v[1] + a.v[2] * b.v[2] + a.v[3] * b.v[3] + a.v[4] * b.v[4];
	return 0;
}

int main()
{
	freopen("in.txt","r",stdin);
	int r,c;
	scanf("%d %d",&r,&c);
	int a[r][c];

	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			scanf("%d",&a[i][j]);

	int k=0;
	for(int i=1;i<r-1;i++)
		for(int j=1;j<c-1;j++)
		{
			pluses[k].cr = i;
			pluses[k].cc = j;
			pluses[k].v[0] = a[i][j-1];
			pluses[k].v[1] = a[i][j];
			pluses[k].v[2] = a[i][j+1];
			pluses[k].v[3] = a[i-1][j];
			pluses[k].v[4] = a[i+1][j];
			k++;
		}			

	int ans = 0;
	// plus hc, ad;
	for(int i=0; i<k; i++)
	{
		for(int j=i+1;j<k;j++)
		{
			int temp = value(pluses[i], pluses[j]);
			// printf("%d", temp);
			if(temp > ans)
			{
				ans = temp;
				// hc = pluses[i];
				// ad = pluses[j];
			}

		}
	}
	// printf("%d (%d, %d) (%d, %d)", ans, hc.cr, hc.cc, ad.cr, ad.cc);
	printf("%d", ans);
}