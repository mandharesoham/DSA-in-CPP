/*
Problem: 540. Single Element in a Sorted Array
Platform: LeetCode
Difficulty: Medium

Tags:
- Array
- Binary Search

Time Complexity: O(log n)
Space Complexity: O(1)

Approach:
Use binary search to locate the single element in the sorted array.
Check whether the current index forms a valid pair based on its parity.
Before the single element, pairs start at even indices. After the single
element, this pattern breaks. Narrow the search space until the unique
element is found.
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int n = nums.size();
        int st = 0;
        int end = n-1;
        if (n == 1)
            return nums[0];
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (mid == 0 && nums[0] != nums[1])
                return nums[mid];
            if (mid == n - 1 && nums[n - 1] != nums[n - 2])
                return nums[mid];

            if (nums[mid - 1] != nums[mid] && nums[mid + 1] != nums[mid])
                return nums[mid];

            if (mid % 2 == 0) {//left
                if (nums[mid] == nums[mid - 1]) {
                    end = mid - 1;
                } else {
                    st = mid + 1;
                }
            }
                else {//right
                    if (nums[mid] == nums[mid - 1]) {
                        st = mid + 1;
                    } else {
                        end = mid - 1;
                    }
                }
            
        }
        return -1;
    }
};
