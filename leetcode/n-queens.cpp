/* -------------------------------------------------------------------------- */
/*                   https://leetcode.com/problems/n-queens/                  */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                 https://leetcode.com/problems/n-queens-ii/                 */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<string>> boards;

    bool aQueenExistsAt(vector<int>& placedQueens, int r, int c) {
        for (int i = 0; i < placedQueens.size(); i++) {
            if (i == r && c == placedQueens[i]) {
                return true;
            }
        }
        return false;
    }

    bool canIPutQueenAt(vector<int>& placedQueens, int r, int c, int n) {
        // Check if a queen already exists int this column
        for (int qr = 0; qr < placedQueens.size(); qr++) {
            int qc = placedQueens[qr];

            if (qc == c) {
                return false;
            }
        }

        // Check Diagonal going towards top left
        for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
            if (aQueenExistsAt(placedQueens, i, j)) {
                return false;
            }
        }

        // Check Diagonal going towards top right
        for (int i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++) {
            if (aQueenExistsAt(placedQueens, i, j)) {
                return false;
            }
        }
        return true;
    }

    void saveBoard(vector<int>& placedQueens, int n) {
        vector<string> board;
        board.reserve(n);
        for (int qr = 0; qr < n; qr++) {
            auto st = string(n, '.');
            st[placedQueens[qr]] = 'Q';
            board.push_back(std::move(st));
        }
        boards.push_back(std::move(board));
    }

    void nQueens(vector<int>& placedQueens, int row, int n) {
        if (row >= n) {
            saveBoard(placedQueens, n);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (canIPutQueenAt(placedQueens, row, col, n)) {
                placedQueens[row] = col;
                nQueens(placedQueens, row + 1, n);
                placedQueens[row] = -1;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<int> queens(n, -1);
        nQueens(queens, 0, n);
        return boards;
    }
};

int main() {
    for (int i = 1; i <= 10; i++) {
        auto s = Solution();
        s.solveNQueens(i);
        cout << i << " " << s.boards.size() << "\n";
    }
}