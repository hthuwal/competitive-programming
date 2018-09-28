class Max_Heap {
	int n;
	int *arr;
public:
	Max_Heap(int n){
		this->n = n;
		arr = new int[n];
	}
	Max_Heap(int a[], int n)
	{
		this->n = n;
		arr = new int[n];
		for (int i = 0; i < n; i++)
			arr[i] = a[i];
		build_heap();
	}
	/*top to bottom heapify*/
	void heapify(int i)
	{
		int largest = i;
		int left = 2 * i + 1;
		int right = 2 * i + 2;
		if (left < n && arr[i] < arr[left])
			largest = left;
		if (right < n && arr[largest] < arr[right])
			largest = right;

		if (largest != i)
		{
			int temp = arr[i];
			arr[i] = arr[largest];
			arr[largest] = temp;
			heapify(largest);
		}
	}

	void build_heap()
	{
		for (int i = n / 2+1; i >= 0; i--)
			heapify(i);
	}

	int extract_max()
	{
		if (n > 0)
		{
			int ans = arr[0];
			arr[0] = arr[n - 1];
			n--;
			heapify(0);
			return ans;
		}
		return -1;
	}
};

void heap_sort(int a[], int l, int h)
{
	int size = h-l+1;
	Max_Heap heap(a, size);
	for (int i = h; i >= l; i--)
	{
		a[i] = heap.extract_max();
	}
}