#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    /* ------------- https://leetcode.com/problems/pascals-triangle ------------- */
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        ans[0] = {1};
        for (int i = 1; i < numRows; i++) {
            ans[i].push_back(1);
            for (int j = 0; j < ans[i - 1].size() - 1; j++) {
                ans[i].push_back(ans[i - 1][j] + ans[i - 1][j + 1]);
            }
            ans[i].push_back(1);
        }
        return std::move(ans);
    }

    /* ------------ https://leetcode.com/problems/pascals-triangle-ii ----------- */
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans(2);
        ans[0] = {1};
        for(int i=1;i<=rowIndex; i++) {
            ans[1].push_back(1);
            for(int j=0; j<ans[0].size()-1; j++) {
                ans[1].push_back(ans[0][j] + ans[0][j+1]);
            }
            ans[1].push_back(1);
            
            ans[0].clear();
            ans[0] = std::move(ans[1]);
        }
        return std::move(ans[0]);
    }
};