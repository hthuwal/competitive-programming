/* -------------------------------------------------------------------------- */
/*        https://leetcode.com/problems/kth-largest-element-in-an-array       */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <queue>

using namespace std;

// Build a Max Heap of all nums: O(n)
// Pop k times to get the kth largest: O(k*log(n))
// Overall Time Complexity: O(n + k * log(n))
int solveSTLMaxHeap(vector<int>& nums, int k) {
    std::priority_queue<int, vector<int>, std::less<int>> heap(nums.begin(), nums.end());
    for (; k > 1; k--) {
        heap.pop();
    }
    return heap.top();
}

// Build a Min heap of first k nums: O(k)
// Iterate over next remaining nums, if they are less than top, remove top and add them: (n-k) * (log k)
// Oerall Time compelxity: O(k + (n-k) log(k))
int solveSTLMinHeap(vector<int>& nums, int k) {
    std::priority_queue<int, vector<int>, std::greater<int>> heap(nums.begin(), nums.begin() + k);
    for (int i = k; i < nums.size(); i++) {
        if (nums[i] > heap.top()) {
            heap.pop();
            heap.push(nums[i]);
        }
    }
    return heap.top();
}

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    cout << solveSTLMinHeap(nums, k) << endl;
    return 0;
}