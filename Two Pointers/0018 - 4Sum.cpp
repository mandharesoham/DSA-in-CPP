/*
Problem: 18. 4Sum
Platform: LeetCode
Difficulty: Medium

Tags:
- Array
- Sorting
- Two Pointers

Time Complexity: O(n³)
Space Complexity: O(1)   // Excluding the output vector

Approach:
Sort the array first. Fix the first two elements using nested loops.
Then use two pointers (left and right) to find the remaining two
elements whose sum equals the target.

Skip duplicate values for both fixed elements and the two pointers
to avoid duplicate quadruplets.
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int tar) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n; ) {
                int p = j + 1;
                int k = n - 1;
                while (p < k) {
                    long long sum = (long long)nums[i] + (long long)nums[j] +
                                    (long long)nums[p] + (long long)nums[k];
                    if (sum > tar) {
                        k--;
                    } else if (sum < tar) {
                        p++;
                    } else {
                        ans.push_back({nums[i], nums[j], nums[p], nums[k]});
                        p++;
                        k--;
                        while (p < k && nums[p] == nums[p - 1])
                            p++;
                    }
                }
                 j++;
                while (j < n && nums[j] == nums[j - 1])
                    j++;
            }
        }
        return ans;
    }
};
