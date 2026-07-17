/*
Problem: 240. Search a 2D Matrix II
Platform: LeetCode
Difficulty: Medium

Tags:
- Array
- Matrix
- Binary Search

Time Complexity: O(m + n)
Space Complexity: O(1)

Approach:
Start from the top-right corner of the matrix.

- If the current element equals the target, return true.
- If the current element is greater than the target, move left.
- If the current element is smaller than the target, move down.

This eliminates one row or one column in every step, resulting in
O(m + n) time complexity.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {

        int m = mat.size();
        int n = mat[0].size();
        int r = 0, c = n - 1;
        while (r < m && c >= 0) {
            if (target == mat[r][c]) {
                return true;
            } else if (target < mat[r][c]) {
                c--;
            } else {
                r++;
            }
        }
        return false;
    }
};
