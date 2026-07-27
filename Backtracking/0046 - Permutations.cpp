/*
Problem: 46. Permutations
Platform: LeetCode
Difficulty: Medium

Tags:
- Array
- Backtracking
- Recursion

Time Complexity: O(n × n!)
Space Complexity: O(n)

Approach:
Generate all possible permutations using backtracking.
Fix one element at the current index and recursively
permute the remaining elements by swapping.
After the recursive call, swap the elements back to
restore the original array (backtracking).
*/

class Solution {
public:
    void getPermutation(vector<int>& nums, int idx, vector<vector<int>>& ans) {
        if (idx == nums.size()) {
            ans.push_back(nums); return;
        }
        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);
            getPermutation(nums, idx + 1, ans);

            swap(nums[idx], nums[i]); // backtracking
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        getPermutation(nums, 0, ans);
        return ans;
    }
};
