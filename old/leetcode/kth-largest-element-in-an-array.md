#### [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/)

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

#### Solution

Use the partition algorithm of quick sort to find correct position of pivot.
if correct position > k:
    partiton algorithm on left half
else 
    partition algorithm on right half

- First element as pivot. Runtime: **20ms**
- Random element as pivot. Runtime: **4ms**


```c++
#define vi vector<int>
class Solution {
public:
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    
    int partition(vi& arr, int i, int j)
    {
        if(i!=j) // for random pivot
        {
            int r = rand() % (j-i) + i;
            swap(arr[i], arr[r]);
        }

        int p = i;
        int x = arr[i];
        for(int k=i+1;k<=j;k++)
        {
            if(arr[k] >= x)
            {
                swap(arr[++p], arr[k]);          
            }
        }
        swap(arr[p], arr[i]);
        return p;
    }
    
    int kthlargest(vi& arr, int i, int j, int k)
    {
        int p = partition(arr, i, j);
        if(p==k)
            return arr[k];
        else if(p>k)
            return kthlargest(arr, i, p-1, k);
        else
            return kthlargest(arr, p+1, j, k);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        return kthlargest(nums, 0, nums.size()-1, k-1);
    }
};
```