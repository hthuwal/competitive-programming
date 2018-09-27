#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

bool ischaotic(int a[], int n)
{
	for(int i=0; i<n;i++)
	{
		if(a[i]-i-1 > 2)
			return true;
	}
	return false;
}

int minimumBribes(int a[], int n)
{
	int b[n];
	int bribes = 0;
	b[0]=a[0];
	for(int i=1;i<n;i++)
	{
		int j = i-1;
		while(b[j]>a[i] && j>=0)
		{
			b[j+1]=b[j];
			bribes++;
			j--;
		}
		b[j+1]=a[i];
	}
	return bribes;
}

int main()
{
	int t;
	int n;
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);
		int arr[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		if(ischaotic(arr, n))
			printf("Too chaotic\n");
		else
			printf("%d\n", minimumBribes(arr, n));
	}
}