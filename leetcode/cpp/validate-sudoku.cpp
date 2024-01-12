/* --------------- https://leetcode.com/problems/valid-sudoku --------------- */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row_counts[10];
        int col_counts[10];
        int cell_counts[10];

        int n = board.size();
        for (int i = 0; i < n; i++) {
            memset(row_counts, 0, sizeof(row_counts));
            memset(col_counts, 0, sizeof(col_counts));
            memset(cell_counts, 0, sizeof(cell_counts));

            int x = 3 * (i / 3);
            int y = 3 * (i % 3);

            for (int j = 0; j < n; j++) {
                if (check_else_update(board, row_counts, i, j)) {
                    return false;
                }

                if (check_else_update(board, col_counts, j, i)) {
                    return false;
                }

                if (check_else_update(board, cell_counts, x + j / 3, y + j % 3)) {
                    return false;
                }
            }
        }
        return true;
    }

    // Returns true if value at board[i][j] has already present in hash
    // else add the entry to hash and returns false
    bool check_else_update(vector<vector<char>>& board, int hash[], int i, int j) {
        if (board[i][j] == '.') {
            return false;
        }

        int num = board[i][j] - '0';
        if (hash[num]) {
            return true;
        }

        hash[num] = 1;
        return false;
    }
};

int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    std::cout << Solution().isValidSudoku(board);
}