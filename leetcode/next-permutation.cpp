/* -------------------------------------------------------------------------- */
/*               https://leetcode.com/problems/next-permutation/              */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int upperBoundInverseSorted(vector<int>& nums, int from, int val) {
        int start = from;
        int end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] <= val) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return start - 1;
    }

    void reverseVector(vector<int>& nums, int start) {
        int i = start;
        int j = nums.size() - 1;
        while (i < j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }

    // The idea is the suffix that is in descending order
    // cannot yield a lexicographically greater permutation
    //
    // - So we find the index beyond which is suffix is in descending order. (O(n)) worst case
    // - Now we swap this with just bigger element in the suffix. binary search O(log(n))
    // - Note even after post swap suffix remains in descending order
    // - Reverse the suffix to make it ascending (lexicographically smallest)
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }

        // Find first character from last which is
        // not in ascending order (right to left)
        int notInDescendingOrder = -1;
        int k = nums.size() - 2;
        for (; k >= 0; k--) {
            if (nums[k] < nums[k + 1]) {
                notInDescendingOrder = k;
                break;
            }
        }

        // The entire list is in descending order lexicographically last permutation
        if (notInDescendingOrder == -1) {
            // reverse it to go backt to first list
            reverseVector(nums, 0);
            return;
        }

        // Find smallest number just greater than nums[k]
        int target = upperBoundInverseSorted(nums, notInDescendingOrder + 1, nums[notInDescendingOrder]);

        swap(nums[notInDescendingOrder], nums[target]);
        reverseVector(nums, notInDescendingOrder + 1);
    }
};

void print(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << "\n";
}

int main() {
    Solution s;
    vector<int> nums{1, 2, 3};
    for (int i = 0; i < 6; i++) {
        s.nextPermutation(nums);
        print(nums);
    }
}