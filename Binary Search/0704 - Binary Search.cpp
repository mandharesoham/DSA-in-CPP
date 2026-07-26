/*
Problem: 704. Binary Search
Platform: LeetCode
Difficulty: Easy

Tags:
- Array
- Binary Search

Time Complexity: O(log n)
Space Complexity: O(1)

Approach:
Use the Binary Search algorithm on the sorted array.
Compare the middle element with the target:
- If equal, return its index.
- If target is smaller, search the left half.
- If target is larger, search the right half.
Continue until the target is found or the search space becomes empty.
*/

class Solution {
public:
    int bs(vector<int>& nums, int target, int st, int end) {

        if (st <= end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] <= target) {
                return bs(nums, target, st = mid + 1, end);
            } else {
                return bs(nums, target, st, end = mid - 1);
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        return bs(nums, target, 0, nums.size() - 1);
    }
};
