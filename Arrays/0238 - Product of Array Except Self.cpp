/*
Problem: 238. Product of Array Except Self
Platform: LeetCode
Difficulty: Medium

Tags:
- Array
- Prefix Product
- Suffix Product

Time Complexity: O(n)
Space Complexity: O(1) (excluding output array)

Approach:
Compute the prefix product for each element and store it in the answer array.
Then traverse from right to left while maintaining a suffix product.
Multiply the current answer with the suffix product to obtain the final result
without using division.
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
       
        
        vector<int> ans(n, 1);
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        // suffix
        int suffix=1;
        for (int i = n - 2; i >= 0; i--) {
            suffix = suffix * nums[i + 1];
             ans[i]=ans[i]*suffix;
        }
       

        return ans;
    }
};
