/*
Problem: 75. Sort Colors
Platform: LeetCode
Difficulty: Medium

Tags:
- Array
- Two Pointers
- Dutch National Flag Algorithm
- Sorting

Time Complexity: O(n)
Space Complexity: O(1)

Approach:
Use three pointers:
- low: points to the position for the next 0
- mid: traverses the array
- high: points to the position for the next 2

If nums[mid] == 0:
    Swap with nums[low] and increment both low and mid.

If nums[mid] == 1:
    Increment mid.

If nums[mid] == 2:
    Swap with nums[high] and decrement high.

This sorts the array in a single traversal without using any extra space.
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int l = 0, mid = 0, h = nums.size() - 1;
        while (mid <= h) {
            if (nums[mid] == 0) {
                swap(nums[l], nums[mid]);
                mid++;
                l++;
            } else if (nums[mid] == 1) {
                mid++;
            }

            else {
                swap(nums[mid], nums[h]);
                h--;
            }
        }
    }
};

