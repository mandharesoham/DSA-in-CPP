/*
Problem: 90. Subsets II
Platform: LeetCode
Difficulty: Medium

Tags:
- Array
- Backtracking
- Recursion
- Sorting

Time Complexity: O(n × 2^n)
Space Complexity: O(n)

Approach:
Sort the array first so duplicates stay together.
Use backtracking to generate subsets.
At each level, skip duplicate elements to avoid repeating the same subset.
Only allow the first occurrence of a duplicate value at the same recursion depth.
*/

class Solution {
public:
    void calculatesubsets(vector<int>& nums, int i, vector<int>& current,
                          vector<vector<int>>& allsubsets) {
        if (i == nums.size()) {
            allsubsets.push_back(current);
            return;
        }
        // include
        current.push_back(nums[i]);
        calculatesubsets(nums, i + 1, current, allsubsets);
        // exclude
        current.pop_back();

        // skipping dublicate values
        int idx = i + 1;
        while (idx < nums.size() && nums[idx] == nums[idx - 1]) {
            idx++;
        }
        calculatesubsets(nums, idx, current, allsubsets);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> current;
        vector<vector<int>> allsubsets;
        calculatesubsets(nums, 0, current, allsubsets);
        return allsubsets;
    }
};
