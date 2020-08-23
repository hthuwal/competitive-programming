void merge(int a[], int l, int mid, int h) {
	int i = l, j = mid + 1, k = 0;	
	int temp[h - l + 1];
	
	for (; i <= mid && j <= h;)
	{
		if (a[i] < a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}

	while (i <= mid)
		temp[k++] = a[i++];
	while (j <= h)
		temp[k++] = a[j++];

	for (int i = 0; i < k; i++)
		a[l + i] = temp[i];

}

void merge_sort(int a[], int l, int h)
{
	if (l < h)
	{
		int mid = (l+h)>>1;
		merge_sort(a, l, mid);
		merge_sort(a, mid + 1, h);
		merge(a, l, mid, h);
	}
}