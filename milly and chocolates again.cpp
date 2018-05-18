#include <iostream>
#include <cstdio>
using namespace std;

/**
 * [BInary search to find the location of number just greater than or equal to x ]
 * @param  arr [array where x is to be searched]
 * @param  l   [lower bound of array from where search is to be started]
 * @param  h   [upper bound of array till where search is to be restricted]
 * @param  x   [element whose upper bound is to be searched (that is number just greater than or equal to x)]
 * @return     [index of upper bound, if every element is smaller than x returns -1]
 */
int bsearch(int arr[],int l,int h,int x)
{
	int m;
	while(l<h)//loop terminates only when we converge to single element that is l==h
	{
		m =(l+h)/2;
		
		if(arr[m]>=x)//if middle element is a candidate for upperbound
			h=m;//there might be smaller upper bounds than arr[m]
		else
			l=m+1;//arr[m] is smaller than x than upper bound might be in the right half
	}

	if(arr[l]>=x)//if element to which we converged is an upper bound
		return l;
	else 
		return -1;//else the element to which we converged is not an upper bound, that is every 
				  //element is smaller than x
}
int main()
{
	/**
	 * reading input from file if not online_judge
	 */
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif


	int n,x;
	int a[110000];

	cin>>n;
	a[0]=0;
	
	for(int i=1;i<=n;i++)	
	{
		cin>>x;
		a[i]=x+a[i-1]; /**
						* storing cumulative frequency //a[i]; denotes combined capacity of c1+c2+...+ci boxes
						* that is up to ith box we would have chocolate number 1 2 3......a[i] chocoloates
						* */
	}

	int q,j;
	cin>>q;

	for(int i=0;i<q;i++)
	{
		cin>>j;
		
		int ans = bsearch(a,1,n,j);
		
		if(ans!=-1)
			cout<<ans<<"\n";
	}
}