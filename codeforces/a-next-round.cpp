#include<iostream>
#include<vector>
#define vi vector<int>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, k;
    cin>>n>>k;
    vi arr(n, 0);
    for (int i = 0; i < n; i++) cin>>arr[i];   
    
    int count=0;
    for(int i=0; i<n; i++) {
        if (arr[i] > 0 && arr[i] >= arr[k-1])
            count++;
    }
    cout<<count;
}