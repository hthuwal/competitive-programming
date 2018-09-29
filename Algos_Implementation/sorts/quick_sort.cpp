#include<cstdlib>
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int partition(int a[], int p, int q)
{
	int x = a[p]; //first element is the pivot element
	int i = p;
	for (int j = i + 1; j <= q; j++)
	{
		if (a[j] <= x)
		{
			i = i + 1;
			swap(a[i], a[j]);
		}
	}
	swap(a[p], a[i]);
	return i;
}

void quick_sort(int a[], int p, int q)
{
	if(p<q)
	{
		int m = partition(a, p, q);
		quick_sort(a, p, m - 1);
		quick_sort(a, m + 1, q);
	}
}