#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>

/*
Sort the strings in lexicographical order

reverse each string

count number of inversions while sorting this list using 
merge sort
*/
using namespace std;

string arr[111111];
long long int inv=0;

string ip()
{
    string i="";
    int temp=getchar_unlocked();
    while(temp<'a'||temp>'z')
        temp=getchar_unlocked();
    while(temp>='a'&&temp<='z')
    {
        i+=(char)temp;
        temp=getchar_unlocked();
    }
    return i;
}

void merge(int l, int mid, int h)
{
    string temp[h-l+1];
    int i = l;
    int j = mid+1;
    int k = 0;
    while(i<=mid && j<=h)
    {
        // cout<<arr[i]<<" "<<arr[j]<<endl;
        if(arr[i] > arr[j])
        {
            temp[k++] = arr[j++];
            inv+=(mid-i+1);
        }
        else{
            temp[k++] = arr[i++];
        }
    }

    while(i<=mid)
        temp[k++]=arr[i++];
    
    while(j<=h)
        temp[k++]=arr[j++];
    
    for(int i=0;i<k;i++)
        arr[l+i]=temp[i];


}
void mergesort(int l, int h)
{
    int mid;
    if(l < h)
    {
        mid = (l+h)>>1;
        mergesort(l, mid);
        mergesort(mid+1, h);
        merge(l, mid, h); 
    }
}
int main()
{
    int n;
    string s;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        s = ip();
        // cout<<s;
        arr[i]=s;
    }
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
        reverse(arr[i].begin(), arr[i].end());
    mergesort(0, n-1);
    cout<<inv<<"\n";
}