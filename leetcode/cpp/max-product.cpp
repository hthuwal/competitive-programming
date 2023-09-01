#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    /* --------- https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product -------- */
    int getMaxLen(vector<int>& nums) {
        int maxLengthPositiveProd = 0;
        int maxLengthNegativeProd = 0;

        if (nums[0] < 0) {
            maxLengthNegativeProd++;
        } else if (nums[0] > 0) {
            maxLengthPositiveProd++;
        }

        int ans = maxLengthPositiveProd;
        for (int i = 1; i < nums.size(); i++) {
            int nnl, npl;
            if (nums[i] < 0) {
                nnl = maxLengthPositiveProd + 1;
                npl = maxLengthNegativeProd == 0 ? 0 : maxLengthNegativeProd + 1;
            } else if (nums[i] > 0) {
                nnl = maxLengthNegativeProd == 0 ? 0 : maxLengthNegativeProd + 1;
                npl = maxLengthPositiveProd + 1;
            } else {
                nnl = 0;
                npl = 0;
            }
            maxLengthNegativeProd = nnl;
            maxLengthPositiveProd = npl;

            ans = max(ans, maxLengthPositiveProd);
        }
        return ans;
    }

    /* --------- https://leetcode.com/problems/maximum-product-subarray/ -------- */
    int maxProduct(vector<int>& nums) {
        int maxIncludingCurrent = nums[0];
        int minIncludingCurrent = nums[0];

        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int c1 = maxIncludingCurrent * nums[i];
            int c2 = minIncludingCurrent * nums[i];

            maxIncludingCurrent = max(c1, nums[i]);
            maxIncludingCurrent = max(c2, maxIncludingCurrent);

            minIncludingCurrent = min(c1, nums[i]);
            minIncludingCurrent = min(c2, minIncludingCurrent);

            if (maxIncludingCurrent > ans) {
                ans = maxIncludingCurrent;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums({2, 3, -2, 4});
    cout << Solution().maxProduct(nums) << "\n";
    nums = {-2, -3, 7};
    cout << Solution().maxProduct(nums) << "\n";
}