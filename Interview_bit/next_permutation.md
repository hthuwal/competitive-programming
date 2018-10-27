### Next Permutation
Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers.  
If such arrangement is not possible, it must be rearranged as the lowest possible order ie, sorted in an ascending order.

[GFG](https://practice.geeksforgeeks.org/problems/next-permutation/0), [InterviewBit](https://www.interviewbit.com/problems/next-permutation/)

#### Without using `std::next_permutation(begin(arr), end(arr))`
[Reference](https://www.geeksforgeeks.org/find-next-greater-number-set-digits/)

```cpp
void Solution::nextPermutation(vector<int> &arr) {
    int n = arr.size();
    int p = -1;
    for(int i=n-2;i>=0;i--)
        if(arr[i] < arr[i+1])
        {
            p=i;
            break;
        }
    if(p==-1)
    {
        sort(begin(arr), end(arr));
        return;
    }
    else
    {
        int d = p+1;
        for(int j=p+2;j<n;j++)
        {
            if(arr[p] < arr[j] and arr[j] < arr[d])
                d = j;
        }
        swap(arr[d], arr[p]);
        sort(begin(arr)+p+1,end(arr));
    }
}
```