/* -------------------------------------------------------------------------- */
/*                 https://leetcode.com/problems/rotate-array                 */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int calcGcd(int a, int b) {
        while (a != 0) {
            // a, b = b % a, a;
            swap(a, b);
            a = a % b;
        }
        return b;
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int gcd = calcGcd(n, k);

        // we need to swap 0, 0+k, 0+2k
        // there will be gcd such groups
        for (int i = 0; i < gcd; i++) {
            int temp = nums[i];
            int j = i;
            while (true) {
                j = (j + k) % n;
                if (j == i) {
                    break;
                }
                swap(temp, nums[j]);
            }
            nums[i] = temp;
        }
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    Solution().rotate(arr, 3);
    for (auto each : arr) {
        cout << each << " ";
    }
    cout << "\n";
}