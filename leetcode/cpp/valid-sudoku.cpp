/* -------------------------------------------------------------------------- */
/*                 https://leetcode.com/problems/valid-sudoku                 */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    bool isValid(vector<vector<char>>& board, int r, int c) {
        unordered_set<char> ans;

        // Check the row
        if (c == -1) {
            for (int i = 0; i < board.size(); i++) {
                if (board[r][i] != '.' && ans.find(board[r][i]) != ans.end()) {
                    return false;
                }
                ans.insert(board[r][i]);
            }
        }
        // Check the column
        else if (r == -1) {
            for (int i = 0; i < board.size(); i++) {
                if (board[i][c] != '.' && ans.find(board[i][c]) != ans.end()) {
                    return false;
                }
                ans.insert(board[i][c]);
            }
        }
        // Check the 3x3 grid
        else {
            for (int i = r; i < r + 3; i++) {
                for (int j = c; j < c + 3; j++) {
                    if (board[i][j] != '.' && ans.find(board[i][j]) != ans.end()) {
                        return false;
                    }
                    ans.insert(board[i][j]);
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            if (!isValid(board, i, -1)) {
                return false;
            }

            if (!isValid(board, -1, i)) {
                return false;
            }
        }

        for (int i = 0; i < board.size(); i += 3) {
            for (int j = 0; j < board.size(); j += 3) {
                if (!isValid(board, i, j)) {
                    return false;
                }
            }
        }
        return true;
    }
};