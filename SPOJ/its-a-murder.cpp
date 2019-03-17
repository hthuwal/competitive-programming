/**
 * https://www.spoj.com/problems/DCEPC206/
 * 
 * Given a list of numbers A.
 * For each number Ai let Bi = Sum (Aj) j>=0 and j<i and A[j] < A[i]
 * 
 * Report Sum (B) 
 * 
 * Solution:
 *      In final answer can be written as:
 *          Sum [ Ai * (Ni) ]
 *          where Ni = Number of elements to the right of i greater than Ai
 *                   = Inversions of Ai (Use Merge Sort)
 *                      
**/

#include <bits/stdc++.h>

#define lli long long int
#define N 111111
using namespace std;

lli merge(lli a[], lli l, lli h, lli mid)
{
    lli i=l, j=mid+1, k=0;
    lli temp[h-l+1];
    lli ans = 0;
    for(;i<=mid && j<=h;)
    {
        if(a[i] < a[j]) 
        {
            temp[k++] = a[i++];
            ans += (a[i-1]) * (h-j+1);
        }
        else 
        {
            temp[k++] = a[j++];
        }
    }

    while(i<=mid)
        temp[k++] = a[i++];
    
    while(j<=h)
        temp[k++] = a[j++];

    for(lli i=0;i<k;i++)
        a[l+i] = temp[i];
    
    return ans;
}

lli mergesort(lli a[], lli l, lli h)
{
    lli ans = 0;
    if(l<h)
    {
        lli mid = l + (h-l) / 2;
        ans += mergesort(a, l, mid);
        ans += mergesort(a, mid+1, h);
        ans += merge(a, l, h, mid);
    }
    return ans;
}

int main()
{
    cin.sync_with_stdio(false);
    lli t,n;
    cin>>t;
    while(t--)
    {
        cin >> n;
        lli a[n];
        for(lli i=0;i<n;i++) cin>>a[i];
        cout<<mergesort(a, 0, n-1)<<endl;
    }
}