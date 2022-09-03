/* -------------------------------------------------------------------------- */
/*                 https://leetcode.com/problems/combinations                 */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void combine_recursive(vector<int>& combs, int choice_number, int ith_choice_starts_at, int n, vector<vector<int>>& ans) {
        if (choice_number == combs.size()) {
            ans.push_back(combs);
            return;
        }

        int num_needed_items = combs.size() - choice_number;
        int num_items_left = n - ith_choice_starts_at + 1;
        if (num_items_left < num_needed_items) {
            return;
        }

        int choice_ends_at = n - num_needed_items + 1;
        for (int j = ith_choice_starts_at; j <= choice_ends_at; j++) {
            combs[choice_number] = j;
            combine_recursive(combs, choice_number + 1, j + 1, n, ans);
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb(k, 0);
        combine_recursive(comb, 0, 1, n, ans);
        return std::move(ans);
    }
};