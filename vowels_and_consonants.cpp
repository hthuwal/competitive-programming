#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
int dp[100001][4];
bool isvowel(char a)
{
    if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u' )
        return true;
    return false;
}
// void print(int i, int l)
// {
// 	for(int j=0;j<i;j++)
// 		cout<<"  ";
// 	for(;i<l;i++)
// 		cout<<dp[1][i]<<" ";
// 	cout<<endl;
// }
int Consonant(string s,int k)
{
	int l = s.length();
	// for(int i=0;i<l;i++)
	// 	cout<<s[i]<<" ";
	// cout<<endl;
	bool ans = true;
	for(int i=0;i<l;i++)
	{
	    dp[1][i]=isvowel(s[i])?0:1;
		if(dp[1][i]<k)
			ans = false;
	}
	// print(0,l);
	if(ans==true)
		return 1;

	for(int j=2;j<=l;j++)
	{

		for(int i=j-1;i<l;i++)
			dp[2][i]=isvowel(s[i])?dp[1][i-1]:dp[1][i-1]+1; 

		ans = true;
		for(int i=j-1;i<l;i++)
		{
			dp[1][i]=dp[2][i];
			if(dp[1][i]<k)
				ans = false;
		}
		// print(j-1,l);
		if(ans==true)
			return j;
	}
	return -1;
}

int main()
{
	cout<<Consonant("ae",1);
}