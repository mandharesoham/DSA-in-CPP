/*
Problem: 74. Search a 2D Matrix
Platform: LeetCode
Difficulty: Medium

Tags:
- Array
- Matrix
- Binary Search

Time Complexity: O(log(m × n))
Space Complexity: O(1)

Approach:
Treat the 2D matrix as a sorted 1D array.
Perform binary search on the virtual array.
For any middle index:
- Row = mid / number_of_columns
- Column = mid % number_of_columns

Compare the target with matrix[row][column] and adjust the search
range until the target is found or the search space becomes empty.
*/

class Solution {
public:
    bool searchINROW(vector<vector<int>>& mat, int row, int target) {
        int n = mat[0].size();
        int st = 0, end = n - 1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (target == mat[row][mid]) {
                return true;
            } else if (target > mat[row][mid]) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
           
        }
         return false;
    }
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size(), n = mat[0].size();
        int stROW = 0, endROW = m - 1;
        while (stROW <= endROW) {
            int midROW = stROW + (endROW - stROW) / 2;
            if (target >= mat[midROW][0] && target <= mat[midROW][n - 1]) {
                return searchINROW(mat, midROW, target); // BS for that row
            } else if (target >= mat[midROW][n - 1]) {
                stROW = midROW + 1;
            } else {
                endROW = midROW - 1;
            }
        }
         return false;
    }
};
