/*### 239. Sliding Window Maximum

- **Difficulty:** Hard
- **Topics:** Queue, Deque, Sliding Window, Monotonic Queue

**Explanation:**
Use a deque to store the indices of elements in decreasing order
of their values.

For every new element, remove elements from the back that are
smaller than or equal to it because they can no longer be the
maximum. Also remove elements from the front when they move
outside the current window.

The element at the front of the deque is always the maximum
element of the current window.

**Time Complexity:** O(n)

**Space Complexity:** O(k)
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;

        // 1st window
        for (int i = 0; i < k; i++) {
            while (dq.size() > 0 && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        for (int i = k; i < nums.size(); i++) {
            res.push_back(nums[dq.front()]);

            // remove window which are not part of current window
            while (dq.size() > 0 && dq.front() <= i - k) {
                dq.pop_front();
            }
            // remove the smaller value
            while (dq.size() > 0 && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        res.push_back(nums[dq.front()]);
        return res;
    }
};
