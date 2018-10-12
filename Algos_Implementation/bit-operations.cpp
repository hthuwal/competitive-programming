#include <bits/stdc++.h>
using namespace std;

/**
 * Return the value of the ith bit of n
 */
int ith_bit(int n, int i)
{
	return (n >> i) & 1;
}

/**
 * Return the number of non zero bits in n
 * O(log2 n) = number of bits in n
 */
int num_of_non_zero_bits(int n)
{
	int count = 0;
	for(;n>0;n>>=1)
		if((n & 1))
			count ++;
	return count;
}

/**
 * Subtraction of 1 from a number toggles all the bits (from right to left) till the rightmost set 
 * bit(including the rightmost set bit). So if we subtract a number by 1 and do bitwise & with itself 
 * (n & (n-1)), we unset the rightmost set bit. If we do n & (n-1) in a loop and count the no of 
 * times loop executes we get the set bit count.
 *
 * O(number of set bits)
 */
int num_of_non_zero_bits_faster(int n)
{
	int count = 0; 
    while (n) 
    { 
      n &= (n-1) ; 
      count++; 
    } 
    return count;
}


/**
 * Return the index of the right most set bit
 */
int rmsb(int n)
{
	return log2(n & -n);
}

void print(string str, int i)
{
	for(int j=0;j<str.length();j++)
		if(i&(1<<j))
			cout<<str[j];
	cout<<endl;
}

void print_all_subsequences(string str)
{
	int n = str.length();
	for(int i=1;i<(int)pow(2,n); i++)
	{
		print(str, i);
	}
}

int main()
{
	int n = 645;
	cout<<ith_bit(n, 0)<<endl;
	cout<<ith_bit(n, 1)<<endl;
	cout<<ith_bit(n, 4)<<endl;

	cout<<num_of_non_zero_bits(n)<<endl;

	print_all_subsequences("Harish");
}