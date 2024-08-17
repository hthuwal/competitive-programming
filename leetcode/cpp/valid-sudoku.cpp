/* -------------------------------------------------------------------------- */
/*                 https://leetcode.com/problems/valid-sudoku                 */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    // Brute Force: Check Every Row, Every Column and Every 3X3 square
    // Time complexity: n^2 + n^2 + n^2 = O(n^2)
    // Space complexity: O(n) for hash
    // 0ms, Beats 100%
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            vector<int> hash(10, 0);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }

                int num = board[i][j] - '0';
                hash[num]++;
                if (hash[num] > 1) {
                    return false;
                }
            }
        }

        for (int i = 0; i < 9; i++) {
            vector<int> hash(10, 0);
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.') {
                    continue;
                }

                int num = board[j][i] - '0';
                hash[num]++;
                if (hash[num] > 1) {
                    return false;
                }
            }
        }

        for (int square = 0; square < 9; square++) {
            int startRow = (square / 3) * 3;
            int startCol = (square % 3) * 3;
            vector<int> hash(10, 0);

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int r = startRow + i;
                    int c = startCol + j;

                    if (board[r][c] == '.') {
                        continue;
                    }
                    int num = board[r][c] - '0';
                    hash[num]++;
                    if (hash[num] > 1) {
                        return false;
                    }
                }
            }
        }

        return true;
    }

    // Brute Force: Go cell by cell and see if the number has been seen in the row, col or square so far
    // Time complexity: n^2 = O(n^2)
    // Space complexity: n*n + n*n + n*(sqrt(n)) = O(n^2)
    // 15ms
    bool isValidSudoku2(vector<vector<char>>& board) {
        // Map of row number and set of characters in that row
        unordered_map<int, unordered_set<char>> rows;

        // Map of col number and set of characters in that col
        unordered_map<int, unordered_set<char>> cols;

        // Map of 3x3 square number and set of characters in that square
        unordered_map<int, unordered_set<char>> squares;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];

                if (c == '.') {
                    continue;
                }

                if (rows[i].find(c) != rows[i].end()) {
                    return false;
                }
                rows[i].insert(c);

                if (cols[j].find(c) != cols[j].end()) {
                    return false;
                }
                cols[j].insert(c);

                int squareNo = (i / 3) * 3 + j / 3;
                if (squares[squareNo].find(c) != squares[squareNo].end()) {
                    return false;
                }
                squares[squareNo].insert(c);
            }
        }

        return true;
    }

    // Same as isValidSudoku2 but using an integer instead of set and doing bitmanipulation instead of set operations
    // Time complexity: n^2 = O(n^2)
    // Space complexity: O(n)
    // 0ms, Beats 100%
    bool isValidSudoku(vector<vector<char>>& board) {
        // If kth bit from right in rows[i]'s bit representation is 1 => that in row i, k has been seen
        int rows[9] = {0};

        // If kth bit from right in cols[i]'s bit representation is 1 => that in col i, k has been seen
        int cols[9] = {0};

        // If kth bit from right in squares[i]'s bit representation is 1 => that in square i, k has been seen
        int squares[9] = {0};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }

                int k = board[i][j] - '0';

                if (rows[i] & (1 << k)) {
                    return false;
                }
                rows[i] |= (1 << k);

                if (cols[j] & (1 << k)) {
                    return false;
                }
                cols[j] |= (1 << k);

                int squareNo = (i / 3) * 3 + j / 3;
                if (squares[squareNo] & (1 << k)) {
                    return false;
                }
                squares[squareNo] |= (1 << k);
            }
        }

        return true;
    }
};
