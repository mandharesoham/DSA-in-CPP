/*
Problem: 51. N-Queens
Platform: LeetCode
Difficulty: Hard

Tags:
- Array
- Backtracking
- Recursion

Time Complexity: O(N!)
Space Complexity: O(N²)

Approach:
Place one queen in each row recursively.
Before placing a queen, check whether the current position
is safe by verifying the column and both diagonals.
If a valid placement is found, continue to the next row.
If no valid placement exists, backtrack by removing the queen
and trying the next column.
*/

class Solution {
public:

    bool isSafe(vector<string>& board, int row, int col, int n) {

        // Check column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q')
                return false;
        }

        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void nQueens(vector<string>& board, int row, int n,
                 vector<vector<string>>& ans) {

        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {

            if (isSafe(board, row, col, n)) {

                board[row][col] = 'Q';

                nQueens(board, row + 1, n, ans);

                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        vector<vector<string>> ans;

        nQueens(board, 0, n, ans);

        return ans;
    }
};
