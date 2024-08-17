/* -------------------------------------------------------------------------- */
/*                 https://leetcode.com/problems/valid-sudoku                 */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    typedef vector<vector<char>> sdk;

    bool isValidRow(sdk& board, int i) {
        vector<bool> present(9, false);
        for (int j = 0; j < board.size(); j++) {
            char c = board[i][j];
            if (c == '.') {
                continue;
            }

            if (present[c - '0']) {
                return false;
            }
            present[c - '0'] = true;
        }
        return true;
    }

    bool isValidCol(sdk& board, int j) {
        vector<bool> present(9, false);
        for (int i = 0; i < board.size(); i++) {
            char c = board[i][j];
            if (c == '.') {
                continue;
            }

            if (present[c - '0']) {
                return false;
            }
            present[c - '0'] = true;
        }
        return true;
    }

    bool isValidCell(int i, int j, sdk& board) {
        vector<bool> present(9, false);
        for (int l = 0; l < 3; l++) {
            for (int k = 0; k < 3; k++) {
                char c = board[l + i][k + j];
                if (c == '.') {
                    continue;
                }

                if (present[c - '0']) {
                    return false;
                }
                present[c - '0'] = true;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            if (!isValidRow(board, i)) {
                return false;
            }

            if (!isValidCol(board, i)) {
                return false;
            }
        }

        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!isValidCell(i, j, board)) {
                    return false;
                }
            }
        }

        return true;
    }
};