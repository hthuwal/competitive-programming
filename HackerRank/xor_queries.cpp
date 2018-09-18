/*
You are given a task to handle q queries. 
In each query, you will be given three positive integers x, l, r. 
You have to choose a number  that lies in the interval [l, r] such that  
x xor y is maximum. Can you find the maximum value of x xor y?
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * converts the ith bit in x from 0 to 1 and 0 to 1
 * Note: here usecase is just to set the bit 
 */
void setbit(int &x, int i)
{
	x = x ^ (1<<i);
}

/**
 * Return the maximum value of X (xor) Y, where y is in range [l,r]
 */
int ans(int x, int l, int r)
{
	int y = 0;
	int max_set_bit = log2(r);
	for(int i=max_set_bit; i>=0 ;i--)
	{
		// if the ith bit is set in x
		// we'll try to have it unset in y
		if( x & (1<<i) ){ 
			// when will it be okay to unset this bit?
			// if the maximum number that can be obtained by unsetting this bit in y. say temp  >= l
			// temp = all 1's from 0 to i-1th bit in y
			// temp = y | ((1<<i) - 1)
			// (1<<i) - 1 => all set bit from [0:i-1]
			
			// since y was already initialized as all 0's we just need to handle the case
			// when we cannot keep ith bit in y unset
			if((y | ((1<<i)-1)) < l )
				setbit(y, i);
		}

		// if the ith bit is unset in x
		// we'll try to set it in y
		else{
			//when will it be okay to set this bit?
			//if setting this bit doesn't make y>r
			if((y^(1<<i)) <= r)
				setbit(y, i);
		}
	}
	return x ^ y;
}

int main()
{
	int q,x,l,r;
	for(scanf("%d",&q); q--; )
	{
		scanf("%d %d %d",&x, &l, &r);
		printf("%d\n", ans(x, l, r));
	}
}