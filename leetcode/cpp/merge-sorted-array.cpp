/* -------------------------------------------------------------------------- */
/*              https://leetcode.com/problems/merge-sorted-array/             */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
     * Try to merge them from backs.
     **/
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0) {
            if (nums1[i] >= nums2[j]) {
                nums1[k] = nums1[i];
                k--;
                i--;
            } else {
                nums1[k] = nums2[j];
                k--;
                j--;
            }
        }

        while (i >= 0) {
            nums1[k] = nums1[i];
            k--;
            i--;
        }

        while (j >= 0) {
            nums1[k] = nums2[j];
            k--;
            j--;
        }
    }
};

int main() {
    vector<int> nums1({1, 2, 3, 0, 0, 0});
    vector<int> nums2({2, 5, 6});
    Solution().merge(nums1, 3, nums2, 3);
    for (int i = 0; i < nums1.size(); i++) {
        cout << nums1[i] << " ";
    }
    cout << "\n";
}