/*
Problem: 2596. Check Knight Tour Configuration
Platform: LeetCode
Difficulty: Medium

Tags:
- Matrix
- Simulation
- Array

Time Complexity: O(n²)
Space Complexity: O(n²)

Approach:
Store the position of every number from 0 to n²-1.
Starting from 0, verify that every consecutive move
forms a valid knight move.
A move is valid if the absolute row and column differences
are (2,1) or (1,2).
If every move is valid, return true; otherwise, return false.
*/

class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int r, int c, int n, int expVal) {
        if (r < 0 || c < 0 || r >= n || c >= n ||
            grid[r][c] != expVal)
            return false;
        if (expVal == n * n - 1)
            return true;

        // 8 possible moves
        int ans1 = isValid(grid, r + 2, c + 1,n, expVal + 1);
        int ans2 = isValid(grid, r + 2, c - 1, n, expVal + 1);
        int ans3 = isValid(grid, r - 2, c + 1, n, expVal + 1);
        int ans4 = isValid(grid, r - 2, c - 1, n,expVal + 1);
        int ans5 = isValid(grid, r + 1, c + 2, n,expVal + 1);
        int ans6 = isValid(grid, r + 1, c - 2, n,expVal + 1);
        int ans7 = isValid(grid, r - 1, c + 2, n,expVal + 1);
        int ans8 = isValid(grid, r - 1, c - 2, n,expVal + 1);

        return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        return isValid(grid, 0, 0, grid.size(), 0);
    }
};
