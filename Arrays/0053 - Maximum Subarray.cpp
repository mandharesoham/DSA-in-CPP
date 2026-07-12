/*
Problem: 53. Maximum Subarray
Platform: LeetCode
Difficulty: Medium

Tags:
- Array
- Dynamic Programming
- Kadane's Algorithm

Time Complexity: O(n)
Space Complexity: O(1)

Approach:
Traverse the array while maintaining the current subarray sum. Reset the current sum to 0 whenever it becomes negative and keep track of the maximum sum encountered.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxs=INT_MIN,cs=0;
        for(int i=0;i<nums.size();i++){
            cs=cs+nums[i];
            maxs=max(maxs,cs);
            if(cs<0)
            cs=0;
        }
        return maxs;
    }
};
