/**
 * https://www.hackerrank.com/challenges/an-interesting-game-1/problem
 */

#include <bits/stdc++.h>
using namespace std;

void gamingArray(vector<int> arr) {
    
    int n = arr.size();
    int max_index [n];
   
    max_index[0]=0;
    for(int i=1;i<n;i++)
        if(arr[max_index[i-1]] < arr[i])
            max_index[i] = i;
        else
            max_index[i] = max_index[i-1];

    int count = 0;
    int l = n-1;
    while(l>=0)
    {
        l = max_index[l]-1;
        count++;
    }
    
    if(count % 2 == 0)
        cout<<"ANDY"<<"\n";
    else
        cout<<"BOB\n";
}

int main()
{
    int t, n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<int> arr(n,0);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        gamingArray(arr);
    }
}
