#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

long merge(vi &a, int l, int m, int h)
{
	int temp[h-l+1];
	int i = l, j=m+1, k=0;
	long inversions = 0;
	while(i<=m && j<=h)
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
		{
			inversions += (m-i+1);
			temp[k++] = a[j++];
		}
	}

	while(i<=m)
		temp[k++] = a[i++];
	while(j<=h)
		temp[k++] = a[j++];	

	for(int i=0; i<k; i++)
		a[l+i] = temp[i];
	return inversions;
}
long mergesort(vi &a, int l, int h)
{
	if(l<h)
	{
		int m = (l+h)/2;
		long iil = mergesort(a,l,m);
		long iir = mergesort(a,m+1,h);
		long iblar = merge(a,l,m,h);
		return iil + iir + iblar;
	}
	return 0;
}

long countInversions(vi arr)
{
	return mergesort(arr, 0, arr.size()-1);
}
int main(){

}