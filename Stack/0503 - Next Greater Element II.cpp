/* ### 503. Next Greater Element II

- **Difficulty:** Medium
- **Topics:** Stack, Monotonic Stack, Array

**Explanation:**
For every element, find the next greater element on its right.
Since the array is circular, after reaching the last element,
we continue checking from the beginning of the array.

A monotonic decreasing stack is used to efficiently find the
next greater element. We process the array twice using `i % n`
so that the circular nature of the array is handled.

**Time Complexity:** O(n)

**Space Complexity:** O(n)
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> s;

        for (int i = 2 * n - 1; i >= 0; i--) {
            while (s.size() > 0 && nums[s.top()] <= nums[i % n]) {
                s.pop();
            }

            ans[i % n] = s.empty() ? -1 : nums[s.top()];
            s.push(i % n);
        }
        return ans;
    }
};
