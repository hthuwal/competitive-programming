#include <bits/stdc++.h>

/**
 * Data structure describing a plus sign
 */
typedef struct plus
{
	int cr, cc;  // row number and column number of the center of the plus
	int v[5];
} plus;


/**
 * List of pluses
 */
plus pluses[3000];


/**
 * Seems LIke an overkill check if doesnt work
 */
bool is_not_overlapped(plus a, plus b)
{

	// if center of both pluses are on the same row then there column should be at least three 3 units apart
	if(a.cr == b.cr)
		return abs(a.cc - b.cc) >= 3;

	// else if center of both pluses are on the same col then there rows should be at least three 3 units apart
	if(a.cc == b.cc)
		return abs(a.cr - b.cr) >= 3;

	// else either there cneter columns or their center rows should be 2 units apart
	return abs(a.cr - b.cr) >= 2 || abs(a.cc - b.cc) >=2;
}

/**
 * Find element wise product of two pluses
 * @param  a plus1
 * @param  b plus2
 * @return plus1 * plus2 if they don't overlap otherwise returns 0
 */
int value(plus a, plus b)
{
	if (is_not_overlapped(a, b))
		return a.v[0] * b.v[0] + a.v[1] * b.v[1] + a.v[2] * b.v[2] + a.v[3] * b.v[3] + a.v[4] * b.v[4];
	return 0;
}

int main()
{
	freopen("in.txt","r",stdin); // For reading input from in.txt directly, Comment this while submitting!
	int r,c;
	scanf("%d %d",&r,&c);
	int a[r][c];

	/**
	 * Reading The matrix
	 */
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			scanf("%d",&a[i][j]);

	int k=0;
	/**
	 * Creating a list of all pluses
	 */
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

	/**
	 * Finding product of every possible pair of pluses, and taking the maximum out of it
	 */
	for(int i=0; i<k; i++)
	{
		for(int j=i+1;j<k;j++)
		{
			int temp = value(pluses[i], pluses[j]);
			if(temp > ans)
			{
				ans = temp;
			}

		}
	}

	printf("%d", ans);
}