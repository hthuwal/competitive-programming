/**
 * KMP Algorithm
 *
 * Your task is so simple given a string and a pattern. 
 * You find the pattern on the given string. 
 * If found print how many time found the pattern and their index. 
 * Otherwise print ‘Not Found’
 *
 * https://www.spoj.com/problems/NAJPF/
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> get_lps(string pat)
{
	int n = pat.length();
	vector<int> pi(n, 0);
	int k = 0;
	for(int i=1;i<n;i++)
	{
		while(k>0 and pat[k] != pat[i])
			k = pi[k-1];

		if(pat[k] == pat[i])
			k ++;

		pi[i] = k;
	}
	return pi;
}

void find(string s, string pat)
{
	vector<int> indices;
	int n = s.length();
	int m = pat.length();
	vector<int> pi = get_lps(pat);
	int k = 0;
	for(int i=0;i<n;i++)
	{
		while(k>0 and pat[k] != s[i])
			k = pi[k-1];
		if(pat[k] == s[i])
			k++;
		if(k==m)
		{
			indices.push_back(i-m+1);
			k = pi[k-1];
		}
	}
	if(indices.size() == 0)
		cout<<"Not Found\n";
	else
	{
		cout<<indices.size()<<"\n";
		for(int i=0;i<indices.size();i++)
		{
			cout<<indices[i]+1<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
}


int main()
{
	int t;
	string s, p;
	cin>>t;
	while(t--)
	{
		cin>>s>>p;
		find(s, p);
	}

}