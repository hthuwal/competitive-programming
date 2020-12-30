#include <bits/stdc++.h>
using namespace std;

map<int, vector<vector<int>>> dict;

int main()
{
	for(int i=2;i<=100;i++)
	{
		for(int j=2;j<=100;j++)
		{
			for(int k=2;k<=100;k++)
			{
				int cube = i*i*i + j*j*j + k*k*k;
				auto values = vector<int>({i,j,k});
				sort(begin(values), end(values));
				
				if (dict.find(cube) == dict.end()) 
					dict[cube] = vector<vector<int>>({values});	
				else
					dict[cube].push_back(values);
			}	
		}		
	}

	for(int i=2;i<=100;i++)
	{
		int cube = i*i*i;
		auto ans = dict.find(cube);
		if(ans != dict.end())
		{
			auto unique = set<vector<int>>(begin(dict[cube]), end(dict[cube]));
			for(auto each: unique)
			{
				printf("Cube = %d, Triple = (%d,%d,%d)\n", i, each[0], each[1], each[2]);
			}
		}
	}
}