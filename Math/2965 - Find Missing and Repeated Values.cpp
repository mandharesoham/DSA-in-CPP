/*
Problem: 2965. Find Missing and Repeated Values
Platform: LeetCode
Difficulty: Easy

Time Complexity: O(n²)
Space Complexity: O(n²)

Approach:
Use an unordered_set to detect the repeated value while computing
the actual sum of all elements. Compare it with the expected sum
of numbers from 1 to n² to determine the missing value.
*/

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int actualsum = 0;
        int expectedsum = 0;
        int rep, unknownnum;

        unordered_set<int> s;
        int n = grid.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                actualsum += grid[i][j];
                if (s.find(grid[i][j]) != s.end()) {
                    rep = grid[i][j];
                    ans.push_back(rep);
                }
                s.insert(grid[i][j]);
            }
        }
        expectedsum = (n * n) * (n * n + 1) / 2;
        unknownnum = expectedsum - actualsum + rep;
        ans.push_back(unknownnum);
        return ans;
    }
};
