/*
Problem: 33. Search in Rotated Sorted Array
Platform: LeetCode
Difficulty: Medium

Tags:
- Array
- Binary Search

Time Complexity: O(log n)
Space Complexity: O(1)

Approach:
The array is rotated, but at least one half (left or right) is always sorted.
At each step:
1. Find the middle element.
2. Determine which half is sorted.
3. Check if the target lies within the sorted half.
4. If yes, search that half; otherwise, search the other half.

This maintains the binary search property and achieves O(log n) time complexity.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0, end = nums.size() - 1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            if (nums[st] <= nums[mid]) { // left sorted
                if (nums[st] <= target && target < nums[mid]) {
                    end = mid - 1;
                } else {
                    st = mid + 1;
                }

            }
            // right
            else {
                if (nums[mid] < target && target <= nums[end]) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};
