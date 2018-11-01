/**
 * https://practice.geeksforgeeks.org/problems/sort-by-set-bit-count/0
 */
#include<bits/stdc++.h>
using namespace std;
int nsb(int a)
{
    int count = 0;
    while(a>0)
    {
        a&=(a-1);
        count ++;
    }
    return count;
}

bool compare(int a, int b)
{  
    return nsb(a) > nsb(b);
}

int main()
 {
	int t, n;
	for(scanf("%d", &t); t--; )
	{
	    scanf("%d",&n);
	    int a[n];
	    for(int i=0;i<n;i++)
	        scanf("%d",&a[i]);
	    stable_sort(a, a+n, compare);
	    for(int i=0;i<n;i++)
	        printf("%d ", a[i]);
	    printf("\n");
	}
	
	return 0;
}
