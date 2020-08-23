/* https://codeforces.com/problemset/problem/1243/A */

#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>

int main()
{
    cin.sync_with_stdio(false);
    int k,n,l;
    cin>>k;
    while(k--) {
        vi freq_of_greater(1111, 0);
        cin>>n;
        for(int i=0;i<n; i++) {
            cin>>l;
            if(l>=n)
               l=n;
            freq_of_greater[l]++; 
        }        
        for(int i=n-1;i>=0;i--)
            freq_of_greater[i] += freq_of_greater[i+1];
        
        int ans = 0;
        for(int i=1;i<=n;i++)
            if(freq_of_greater[i] >= i)
                ans = i;
        cout<<ans<<"\n";
    }
}