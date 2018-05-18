#include <cstdio>
#include <ctime>
#include <cstdlib>

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

#define vi vector<int>

int main()
{
    int n;
    scanf("%d",&n);
    vi arr(n,0);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    arr 
    if(n%2==0)
        printf("%d\n",randmoized_selection(arr,0,n-1,(n/2)-1));
    else
        printf("%d\n",randmoized_selection(arr,0,n-1,(n/2)));
}