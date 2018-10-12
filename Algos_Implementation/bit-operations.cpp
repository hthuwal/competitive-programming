#include <bits/stdc++.h>
using namespace std;

int ith_bit(int n, int i)
{
	return (n >> i) & 1;
}

int num_of_non_zero_bits(int n)
{
	int count = 0;
	for(;n>0;n>>=1)
		if((n & 1))
			count ++;
	return count;
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