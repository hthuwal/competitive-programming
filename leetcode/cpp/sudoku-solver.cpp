/* -------------- https://leetcode.com/problems/sudoku-solver/ -------------- */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   private:
    bool canPlace(vector<vector<char>>& board, int row, int col, int val) {
        int square_x = 3 * (row / 3);
        int square_y = 3 * (col / 3);

        for (int i = 0; i < 9; i++) {
            // Check row
            if (board[row][i] == '0' + val) {
                return false;
            }

            // Check col
            if (board[i][col] == '0' + val) {
                return false;
            }

            // Check my square
            if (board[square_x + i / 3][square_y + i % 3] == '0' + val) {
                return false;
            }
        }
        return true;
    }

    bool solveSudokuRecursive(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                // If this cell is not empty continue
                if (board[row][col] != '.') {
                    continue;
                }

                for (int val = 1; val <= 9; val++) {
                    // If I cannot place this value continue to other values
                    if (!canPlace(board, row, col, val)) {
                        continue;
                    }

                    // If can place value, try placing it and recursively solving it
                    board[row][col] = '0' + val;
                    if (solveSudokuRecursive(board)) {
                        return true;  // Return if it was solved recusively
                    }

                    // If it wasn't solved recursively backtrack
                    board[row][col] = '.';
                }

                // If we are not able to place any value here. Not a valid solution return false
                return false;
            }
        }

        return true;
    }

   public:
    void solveSudoku(vector<vector<char>>& board) { solveSudokuRecursive(board); }

    // Print sudoku with boundaries
    void printSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            if (row % 3 == 0) {
                cout << "-------------------------" << endl;
            }
            for (int col = 0; col < 9; col++) {
                if (col % 3 == 0) {
                    cout << "| ";
                }
                cout << board[row][col] << " ";
            }
            cout << "|" << endl;
        }
        cout << "-------------------------" << endl;
    }

};

int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    auto s = Solution();
    s.printSudoku(board);
    s.solveSudoku(board);
    s.printSudoku(board);
}