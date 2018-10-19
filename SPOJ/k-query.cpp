/**
 * https://www.spoj.com/problems/KQUERY/
 *
 * Fenwick Tree (or Segment Tree), offline processing
 */

#include<bits/stdc++.h>
#define N 30003

int bit[N];
int n;

void update(int i)
{
	for(;i<=n;i+=(i&-i))
		bit[i] += 1;
}

int getcount(int i)
{
	int sum = 0;
	for(;i>=1;i-=(i&-i))
		sum += bit[i];
	return sum;
}

class Cell{
public:
	int type; // 0 => array element, 1 => query element
	int value; // value if array element, the 
	int index; //index of number in array or the index of query
	int i;
	int j;

	// constructor to store array
	Cell(int val, int idx)
	{
		value = val; index = idx; type = 0;
		i = j =-1;
	}

	// constructor to store queries
	Cell(int i, int j, int val, int idx)
	{
		this->i = i; this->j = j; type = 1;
		value = val; index = idx;
	}

	// to sort list of cells in descending order of values
	// no need to provide compare function
	bool operator<(const Cell &c)
	{
		if(value != c.value)
			return value > c.value;
		
		return type > c.type;
	}
};

std::vector<Cell> arr;

int main()
{
	int q, x, y, z;
	scanf("%d",&n);
	int k=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&z);
		arr.push_back(Cell(z, i+1));
	}

	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		scanf("%d %d %d", &x, &y, &z);
		arr.push_back(Cell(x, y, z, i));
	}

	std::sort(arr.begin(), arr.end());

	// for(int i=0;i<n+q;i++)
	// 	std::cout<<arr[i].type<<" "<<arr[i].value<<"\n";

	memset(bit, 0, sizeof(bit));
	int answers[q];

	for(int x=0;x<n+q;x++)
	{
		if(arr[x].type==0)
			update(arr[x].index);
		else
		{
			if(arr[x].i == 1)
				answers[arr[x].index] = getcount(arr[x].j);
			else
				answers[arr[x].index] = getcount(arr[x].j) - getcount(arr[x].i-1);
		}
	}
	
	for(int i=0;i<q; i++)
		std::cout<<answers[i]<<"\n";

}