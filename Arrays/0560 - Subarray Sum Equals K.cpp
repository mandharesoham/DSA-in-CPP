/*
Problem: 560. Subarray Sum Equals K
Platform: LeetCode
Difficulty: Medium

Tags:
- Array
- Brute Force

Time Complexity: O(n²)
Space Complexity: O(1)

Approach:
Iterate through each starting index and calculate the sum of all
subarrays beginning at that index. Increment the count whenever
the running sum equals k.
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {

                sum += nums[j];
                if (sum == k) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
