/*
Problem: 39. Combination Sum
Platform: LeetCode
Difficulty: Medium

Tags:
- Array
- Backtracking
- Recursion

Time Complexity: O(2^n) (Approximate)
Space Complexity: O(target)

Approach:
Use backtracking to explore all possible combinations.
At each index, we have two choices:
1. Include the current element (stay at the same index since it can be reused).
2. Exclude the current element and move to the next index.
If the target becomes 0, store the current combination.
If the target becomes negative or all elements are processed, backtrack.
*/

class Solution {
public:
    set<vector<int>> s;
    void getAllCombination(vector<int>& arr, int tar, int i,
                           vector<vector<int>>& ans, vector<int>& combi) {
        if (i == arr.size() || tar < 0) {
            return;
        }
        if (tar == 0) {
            if (s.find(combi) == s.end()) {
                ans.push_back(combi);
                s.insert(combi);
                return;
            }
        }

        // inclusion
        combi.push_back(arr[i]);
        getAllCombination(arr, tar - arr[i], i + 1, ans, combi);

        // multiple
        getAllCombination(arr, tar - arr[i], i, ans, combi);
        combi.pop_back();

        // exclusion
        getAllCombination(arr, tar, i + 1, ans, combi);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {

        vector<vector<int>> ans;
        vector<int> combi;
        getAllCombination(arr, target, 0, ans, combi);
        return ans;
    }
};
