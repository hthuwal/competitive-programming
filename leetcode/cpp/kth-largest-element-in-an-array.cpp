/* -------------------------------------------------------------------------- */
/*        https://leetcode.com/problems/kth-largest-element-in-an-array       */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <queue>

using namespace std;

/* -------------------------------- O (nlogk) ------------------------------- */

int findKthSmallest(vector<int>& nums, int k) {
    std::priority_queue<int> max_heap;
    for (int i = 0; i < nums.size(); i++) {
        if (i < k) {
            max_heap.push(nums[i]);
        } else {
            int top = max_heap.top();
            if (nums[i] < top) {
                max_heap.pop();
                max_heap.push(nums[i]);
            }
        }
    }
    return max_heap.top();
}


int findKthLargestHeap(vector<int>& nums, int k) { return findKthSmallest(nums, nums.size() - k + 1); }


int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    cout << findKthLargestHeap(nums, k) << endl;
    return 0;
}