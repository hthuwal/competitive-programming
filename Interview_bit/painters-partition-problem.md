## [Painters Partition Problem](https://www.interviewbit.com/problems/painters-partition-problem/)

[Same Problem on GFG](https://practice.geeksforgeeks.org/problems/the-painters-partition-problem/0)

You have to paint N boards of length {A0, A1, A2, A3 … AN-1}. There are K painters available and you are also given how much time a painter takes to paint 1 unit of board. You have to get this job done as soon as possible under the constraints that any painter will only paint contiguous sections of board.

- 2 painters cannot share a board to paint. That is to say, a board
cannot be painted partially by one painter, and partially by another.
- A painter will only paint contiguous boards. Which means a
configuration where painter 1 paints board 1 and 3 but not 2 is
invalid.

Return the ans % 10000003

---

#### O(n log(sum(arr))) solution

```cpp
#define lli long long int

/**
 * Return true if it is possible to paing the entire 
 * board using less than k painters provided each painter
 * will not paint more than `max_board_length`
 */
bool verify(vector<int> &a, lli max_board_length, int k)
{
    lli num_painters = 0;
    lli n = a.size();
    int i = 0;
    while(i<n)
    {
        if(a[i] > max_board_length)
            return false;
        lli ti = a[i];
        num_painters++;
        i++;
        while(i<n and ti+a[i]<=max_board_length)
        {
            ti += a[i];
            i++;
        }
        
    }
    return num_painters <= k;
}

/**
 * Binary Search over answer space
 */
int Solution::paint(int k, int x, vector<int> &a) {
    lli lb = 0;
    lli ub = (int)1e18; // could also be set to sum of array a
    while(lb<=ub)
    {
        lli mid = lb+(ub-lb)/2;
        if(verify(a, mid, k))
            ub = mid - 1;
        else
            lb = mid + 1;
    }
    return (((ub+1)%10000003) * x) % 10000003 ;
}
```