/* -------------------------------------------------------------------------- */
/*               https://leetcode.com/problems/arithmetic-slices              */
/* -------------------------------------------------------------------------- */

#include <chrono>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   private:
    // Given that we have `len` elements such that nums[i] - nums[i-1] is same for all i
    // Returns total number of subAarrays of lengthe >= 3
    int numberOfArithmeticSlicesUtil(int len) {
        int total_sub_arrays = len * (len + 1) / 2;
        int sub_arrays_of_size_2 = len - 1;
        int sub_arrays_of_size_1 = len;
        int arithmeticSlices = total_sub_arrays - sub_arrays_of_size_1 - sub_arrays_of_size_2;
        return arithmeticSlices;
    }

   public:
    /* ------------------ Brute force: O(n^2) time, O(1) space ------------------ */
    int numberOfArithmeticSlicesBruteForce(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n - 2; i++) {
            int diff = nums[i + 1] - nums[i];
            for (int j = i + 2; j < n; j++) {
                if (nums[j] - nums[j - 1] != diff) {
                    break;
                } else {
                    ans++;
                }
            }
        }
        return ans;
    }

    /* --------------------- O(n) time, O1() space solution --------------------- */
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return 0;
        }

        int len = 2;
        int ans = 0;
        int diff = nums[1] - nums[0];

        for (int i = 2; i < n; i++) {
            if (nums[i] - nums[i - 1] == diff) {
                len++;
            } else {
                if (len > 2) {
                    ans += numberOfArithmeticSlicesUtil(len);
                }
                // Reset to start checking from from i-1;
                diff = nums[i] - nums[i - 1];
                len = 2;
            }
        }

        if (len > 2) {
            ans += numberOfArithmeticSlicesUtil(len);
        }
        return ans;
    }

    /* -------------- Unnecessary DP: O(n^2) space and O(n^2) time -------------- */
    int numberOfArithmeticSlicesDP(vector<int>& nums) {
        int n = nums.size();
        int dp[2][n + 1];

        for (int i = 0; i <= n; i++) {
            dp[0][i] = 0;
            dp[1][i] = 0;
        }

        // dp[i][l] denotes the arithmetic subarray of length l ending at i
        int ans = 0;
        for (int i = 2; i <= nums.size() - 1; i++) {
            for (int l = 3; l <= nums.size(); l++) {
                if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                    dp[1][l] = l == 3 ? 1 : dp[0][l - 1];
                } else {
                    dp[1][l] = 0;
                }
            }

            for (int l = 3; l <= nums.size(); l++) {
                dp[0][l] = dp[1][l];
                ans += dp[0][l];
            }
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    cout << Solution().numberOfArithmeticSlicesDP(nums)<<" ";
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()
              << "[µs]" << std::endl;

    begin = std::chrono::steady_clock::now();
    cout << Solution().numberOfArithmeticSlicesBruteForce(nums)<<" ";
    end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()
              << "[µs]" << std::endl;

    begin = std::chrono::steady_clock::now();
    cout << Solution().numberOfArithmeticSlices(nums)<<" ";
    end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()
              << "[µs]" << std::endl;
}