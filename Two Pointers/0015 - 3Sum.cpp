/*
Problem: 15. 3Sum
Platform: LeetCode
Difficulty: Medium

Tags:
- Array
- Sorting
- Two Pointers

Time Complexity: O(n²)
Space Complexity: O(1)   // Excluding the output vector

Approach:
Sort the array first. Iterate through each element and fix it as the
first element of the triplet. Then use two pointers (left and right)
to find two numbers whose sum equals the negative of the fixed element.

Skip duplicate elements for both the fixed element and the two pointers
to avoid duplicate triplets.
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                } else {
                        ans.push_back({nums[i], nums[j], nums[k]});
                        j++;
                        k--;
                        while (j < k && nums[j] == nums[j - 1])
                            j++;
                    }
            }
        }
        return ans;
    }
};
