/**
 * Asked in Microsoft
 *
 * https://www.geeksforgeeks.org/reorder-a-array-according-to-given-indexes/
 *
 * in costant space
 */
#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;

void auxillary(vi &arr, vi ind)
{
	vi temp(arr.size());
	for(int i=0;i<arr.size();i++)
	{
		temp[ind[i]] = arr[i];
	}
	arr.assign(temp.begin(), temp.end());
}

void inplace(vi &arr, vi ind)
{
	for(int i=0;i<arr.size();i++)
	{
		while(ind[i] != i)
		{
			swap(arr[ind[i]], arr[i]);
			swap(ind[ind[i]], ind[i]);
		}
	}
}
void print(vi a)
{
	for(int i=0;i<a.size();i++)
		cout<<a[i]<<"\t";
	cout<<"\n";
}

int main()
{
	int ar[] = {50, 40, 70, 60, 90}; 
    int in[] = {3,  0,  4,  1,  2}; 

    vi arr(ar, ar+5);
    vi ind(in, in+5);

    cout<<"Original arr and indices\n";
    print(arr);
    print(ind);


    auxillary(arr, ind);
    cout<<endl<<"Using Auxillary array method: O(n) extra space\n";
    print(arr);

    arr.assign(ar, ar+5);
    cout<<"\nOriginal arr and indices\n";
    print(arr);
    print(ind);

    inplace(arr, ind);
    cout<<endl<<"Inplace: O(1) extra space\n";
    print(arr);
}