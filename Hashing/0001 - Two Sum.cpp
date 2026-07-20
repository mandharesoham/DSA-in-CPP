/*
Problem: 1. Two Sum
Platform: LeetCode
Difficulty: Easy

Tags:
- Array
- Hash Table

Time Complexity: O(n)
Space Complexity: O(n)

Approach:
Use an unordered_map to store each number and its index while traversing
the array. For every element, check whether its complement
(target - current element) already exists in the hash map.
If found, return the indices of the complement and the current element.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int first = nums[i];
            int second = target - first;
            if (m.find(second) != m.end()) {
                ans.push_back(i);
                ans.push_back(m[second]);
                break;
            }
            m[first] = i;
        }
        return ans;
    }
};
