/*
Problem: 136. Single Number
Platform: LeetCode
Difficulty: Easy

Tags:
- Array
- Bit Manipulation
- XOR

Time Complexity: O(n)
Space Complexity: O(1)

Approach:
Use the XOR operation on all elements.
Since x ^ x = 0 and x ^ 0 = x, every duplicate element cancels out,
leaving only the element that appears once.
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i : nums){
            ans=ans^i;
        }
        return ans;
    }
};
