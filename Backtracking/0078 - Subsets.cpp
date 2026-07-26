/*
Problem: 78. Subsets
Platform: LeetCode
Difficulty: Medium

Tags:
- Array
- Backtracking
- Recursion

Time Complexity: O(n × 2^n)
Space Complexity: O(n)

Approach:
Use backtracking to generate all possible subsets.
For each element, make two choices:
1. Include the current element.
2. Exclude the current element.

When all elements have been processed, add the current subset
to the answer.
*/

class Solution {
public:
    void calculatesubsets(vector<int>& nums, int i, vector<int>& ans,
                          vector<vector<int>>& allsubsets) {
        if (i == nums.size()) {
            allsubsets.push_back({ans});
            return;
        }
        // include
        ans.push_back(nums[i]);
        calculatesubsets(nums, i + 1, ans, allsubsets);

        // exclude
        ans.pop_back();
        calculatesubsets(nums, i + 1, ans, allsubsets);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allsubsets;
        vector<int> ans;
        calculatesubsets(nums, 0, ans, allsubsets);
        return allsubsets;
    }
};
