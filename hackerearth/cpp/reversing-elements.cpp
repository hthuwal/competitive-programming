/**
 * https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/reversing-segments-53046b15/
 */
#include <bits/stdc++.h>
#define lli long long int

using namespace std;

/*
Segment tree of the following data type
ms -> maximum sum sub array in the array denoted by the seg tree node
ls -> maximum sum sub array including the left most element in the array denoted by the seg tree node
rs -> maximum sum sub array including the right most element in the array denoted by the seg tree node
s -> total sum of the array denoted by the seg tree node
 */
struct quad{
    lli ms;
    lli ls;
    lli rs;
    lli s;
};


lli arr[100005]; // original array to store the numbers

quad tree[300004]; // array representation of the segment tree

/**
 * Create segment tree
 * ti -> tree index (tree[ti] is some node of segment tree) -> aggregates over arr[si: ei]
 */
void create(lli ti, lli si, lli ei)
{
    if(si==ei)
    {
        tree[ti] = {arr[si], arr[si], arr[si], arr[si]};
    }
    else if(si < ei)
    {
        lli left = 2*ti+1;
        lli right = 2*ti+2;
        lli mid = si + (ei-si)/2;

        create(left, si, mid);
        create(right, mid+1, ei);
        
        tree[ti].ms = max(tree[left].ms, tree[right].ms);
        tree[ti].ms = max(tree[ti].ms, tree[left].rs + tree[right].ls);
        
        tree[ti].ls = max(tree[left].ls, tree[left].s+ tree[right].ls);
        tree[ti].rs = max(tree[right].rs, tree[right].s + tree[left].rs);
        
        tree[ti].s = tree[left].s + tree[right].s;
    }
}

/**
 * Merging the aggregates of left half and right half
 *
 * This usually is not coded as a seperate function but rather written 
 * directly inside the get_max function.
 *
 * But here this step was required in the main. So coded it seperately
 */
quad merge(quad l_arr, quad r_arr)
{
    quad ans;
    if(l_arr.ms != INT_MIN and r_arr.ms != INT_MIN)
    {
        ans.ms = max(l_arr.ms, r_arr.ms);
        ans.ms = max(ans.ms, l_arr.rs + r_arr.ls);
        
        ans.ls = max(l_arr.ls, l_arr.s + r_arr.ls);
        ans.rs = max(r_arr.rs, r_arr.s + l_arr.rs);
        
        ans.s = l_arr.s + r_arr.s;
    }
    else if(l_arr.ms != INT_MIN)
        ans = l_arr;
    else
        ans = r_arr;
    return ans;
}

/**
 * Return the quad structure for the arr range[rs: ri]
 *
 * ti -> tree index (tree[ti] is some node of segment tree) -> aggregates over arr[si: ei]
 */
quad get_max(lli ti, lli si, lli ei, lli rs, lli re)
{
    if(si >= rs and ei <= re)
        return tree[ti];
    
    if(si > re or ei < rs)
        return {INT_MIN, INT_MIN, INT_MIN, INT_MIN};
    
    lli left = 2*ti+1;
    lli right = 2*ti+2;
    lli mid = si+(ei-si)/2;
    
    quad l_arr = get_max(left, si, mid, rs, re);
    quad r_arr = get_max(right,mid+1, ei, rs, re);
    
    return merge(l_arr, r_arr);
}

int main()
{
    ios::sync_with_stdio(false);
    lli n, q, l, r;
    cin>>n>>q;
    for(lli i=0;i<n;i++)
        cin>>arr[i];
        
    create(0, 0, n-1);
    
    while(q--)
    {
        cin>>l>>r;
        l--; r--;

        // find the quad ds 0 to l
        quad left = get_max(0, 0, n-1, 0, l-1);

        // find the quad ds between l and r
        quad middle = get_max(0, 0, n-1, l, r);

        // find the quad ds between r+1 to end
        quad right = get_max(0, 0, n-1, r+1, n-1);
        
        // since middle was supposed to be reversed (ther ls and rs will change)
        swap(middle.ls, middle.rs);

        // merge the answers
        quad ans = merge(left, middle);
        ans = merge(ans, right);
        cout<<ans.ms<<"\n";
    }
}