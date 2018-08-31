#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

class Heap{
private:
	bool ismin;
	vi nodes;
public:
	Heap(bool min=true){
		this->ismin = min;
	}
	bool compare(int child, int parent, bool min)
	{
		if (min)
			return child < parent;
		else
			return child > parent;
	}
	int add(int value){
		nodes.push_back(value);
		int i = nodes.size()-1;
		while(i!=0 and compare(nodes[i], nodes[(i-1)/2], ismin))
		{
			int temp = nodes[i];
			nodes[i] = nodes[(i-1)/2];
			nodes[(i-1)/2] = temp;
			i = (i-1)/2;
		}
		return i;
	}
	int find(int value)
	{
		for(int i=0;i<nodes.size();i++)
		{
			if(nodes[i] == value)
				return i;
		}
		return -1;
	}
	void heapify(int i, int n)
	{
		int left = 2*i+1;
		int right = 2*i+2;
		int temp, best;
		if(left<n and compare(nodes[left], nodes[i], ismin))
			best = left;
		else
			best = i;

		if(right<n and compare(nodes[right], nodes[best], ismin))
			best = right;

		if(best != i)
		{
			temp = nodes[best];
			nodes[best] = nodes[i];
			nodes[i] = temp;
			heapify(best, n);
		}
	}

	int size()
	{
		return nodes.size();
	}

	int get_root(bool pop=false)
	{
		if (nodes.size() == 0)
			return -1;
		int ans = nodes[0];
		if(pop)
		{
			nodes[0] = nodes.back();
			nodes.pop_back();
			heapify(0, nodes.size());
		}
		return ans;
	}
	void print()
	{
		for(int i=0;i<nodes.size();i++)
			cout<<nodes[i]<<" ";
		cout<<endl;
	}	
	int modify(int i, int new_val)
	{
		nodes[i] = new_val;
		while(i!=0 and compare(nodes[i], nodes[(i-1)/2], ismin))
		{
			int temp = nodes[i];
			nodes[i] = nodes[(i-1)/2];
			nodes[(i-1)/2] = temp;
			i = (i-1)/2;
		}
		return i;
	}
	void del(int i)
	{
		if(ismin){
			modify(i, INT_MIN);
			get_root(true);
		}

		else{
			modify(i, INT_MAX);
			get_root(true);
		}
	}
};

int main()
{
    int n, d;
    Heap min_heap = Heap();
    Heap max_heap = Heap(false);

    scanf("%d %d",&n,&d);
    
    int arr[n];
    
    int ans=0;
    float current_median = -1.0;

    for(int i=0; i<n; i++)
    {
    	scanf("%d",&arr[i]);
    	if(arr[i]<current_median)
    		max_heap.add(arr[i]);
    	else
    		min_heap.add(arr[i]);
    	
    	if(i >= d)
    	{

    		if(2*current_median <= arr[i])
    			ans ++;	
    		if(min_heap.find(arr[i-d]) != -1)
    			min_heap.del(min_heap.find(arr[i-d]));
    		else
    			max_heap.del(max_heap.find(arr[i-d]));

    	}
    	

    	int size_minh = min_heap.size();
    	int size_maxh = max_heap.size();

    	if (size_minh > size_maxh + 1)
    		max_heap.add(min_heap.get_root(true));
    	else if(size_maxh > size_minh + 1)
    		min_heap.add(max_heap.get_root(true));

    	// update the current median
    	size_minh = min_heap.size();
    	size_maxh = max_heap.size();	

    	if(size_maxh == size_minh)
    		current_median = (max_heap.get_root() + min_heap.get_root()) / 2.0;
    	else if(size_maxh > size_minh)
    		current_median = max_heap.get_root();
    	else
    		current_median = min_heap.get_root();
    }
    printf("%d", ans);
}