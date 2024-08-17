/* ------- https://leetcode.com/problems/product-of-array-except-self/ ------ */

#include <vector>

using namespace std;

class Solution {
   public:
    // Time complexity: O(n)
    // Space complexity: O(n)
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<long> prefix(nums.size(), 0);
        vector<long> postfix(nums.size(), 0);

        int n = nums.size();

        // Prefix Products
        prefix[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        // Postfix Products
        postfix[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            postfix[i] = postfix[i + 1] * nums[i + 1];
        }

        vector<int> result(nums.size(), 0);
        for (int i = 0; i < n; i++) {
            result[i] = prefix[i] * postfix[i];
        }

        return result;
    }

    // Time complexity: O(n)
    // Space complexity: O(1)
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        int prefix = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = prefix;
            prefix *= nums[i];
        }

        int postfix = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= postfix;
            postfix *= nums[i];
        }

        return ans;
    }
};