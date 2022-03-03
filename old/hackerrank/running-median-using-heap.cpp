#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

class Min_heap{
private:
	vi nodes;
public:
	/**
	 * THis method asumes that the subtrees are already heapified
	 */
	void min_heapify(int i, int n)
	{
		int left = 2*i+1;
		int right = 2*i+2;
		int temp, smallest;
		if(left<n && nodes[left] < nodes[i])
			smallest = left;
		else
			smallest = i;

		if(right<n && nodes[right] < nodes[smallest])
			smallest = right;

		if(smallest != i)
		{
			temp = nodes[smallest];
			nodes[smallest] = nodes[i];
			nodes[i] = temp;
			min_heapify(smallest, n);
		}
	}
	void add(int value)
	{
		nodes.push_back(value); // add node at the end
		int i = nodes.size()-1;
		while(i!=0 && nodes[(i-1)/2] > nodes[i]) // while parent is greater than value, replace parent
		{
			int temp = nodes[i];
			nodes[i] = nodes[(i-1)/2];
			nodes[(i-1)/2] = temp;
			i = (i-1)/2;
		}
	}
	int size()
	{
		return nodes.size();
	}
	int get_min()
	{
		if(size() == 0)
			return -1;
		return nodes[0];
	}
	int extract(){
		if(size() == 0)
			return -1;
		int ans = nodes[0];
		nodes[0] = nodes.back();
		nodes.pop_back();
		min_heapify(0, size());
		return ans;
	}
	void print()
	{
		for(int i=0;i<nodes.size();i++)
			cout<<nodes[i]<<" ";
		cout<<endl;
	}
};

class Max_heap{
private:
	vi nodes;
	bool max;
	bool min;
public:
	/**
	 * THis method asumes that the subtrees are already heapified
	 */
	void max_heapify(int i, int n)
	{
		int left = 2*i+1;
		int right = 2*i+2;
		int temp, largest;
		if(left<n && nodes[left] > nodes[i])
			largest = left;
		else
			largest = i;

		if(right<n && nodes[right] > nodes[largest])
			largest = right;

		if(largest != i)
		{
			temp = nodes[largest];
			nodes[largest] = nodes[i];
			nodes[i] = temp;
			max_heapify(largest, n);
		}
	}
	void add(int value)
	{
		nodes.push_back(value);
		int i = nodes.size()-1;
		while(i!=0 && nodes[(i-1)/2] < nodes[i])
		{
			int temp = nodes[i];
			nodes[i] = nodes[(i-1)/2];
			nodes[(i-1)/2] = temp;
			i = (i-1)/2;
		}
	}
	int size()
	{
		return nodes.size();
	}
	int get_max()
	{
		if(size() == 0)
			return -1;
		return nodes[0];
	}
	int extract(){
		if(size() == 0)
			return -1;
		int ans = nodes[0];
		nodes[0] = nodes.back();
		nodes.pop_back();
		max_heapify(0, size());
		return ans;
	}
	void print()
	{
		for(int i=0;i<nodes.size();i++)
			cout<<nodes[i]<<" ";
		cout<<endl;
	}
};

int main()
{
	int n,a,size_minh,size_maxh;
	float ans = -1;
	Min_heap minh = Min_heap();
	Max_heap maxh = Max_heap();
	for(scanf("%d",&n);n--;)
	{
		scanf("%d",&a);
		if(a < ans)
			maxh.add(a);
		else
			minh.add(a);

		size_minh = minh.size();
		size_maxh = maxh.size();
		
		if (size_minh > size_maxh + 1)
			maxh.add(minh.extract());
		else if(size_maxh > size_minh + 1)
			minh.add(maxh.extract());

		size_minh = minh.size();
		size_maxh = maxh.size();

		if (size_minh == size_maxh)
			ans = (maxh.get_max() + minh.get_min()) / 2.0;
		else if (size_maxh > size_minh)
			ans = maxh.get_max();
		else
			ans = minh.get_min();
		printf("%0.1f\n",ans);		
	}
}