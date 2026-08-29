/*### 42. Trapping Rain Water

- **Difficulty:** Hard
- **Topics:** Array, Two Pointers

**Explanation:**
Use two pointers, `l` and `r`, starting from the left and right
ends of the array. Maintain `lmax` and `rmax` to store the maximum
height encountered from each side.

At each step, compare `lmax` and `rmax`. If `lmax` is smaller,
the water trapped at the left pointer can be calculated because
the right side has a taller boundary. Otherwise, calculate the
water at the right pointer.

Move the corresponding pointer inward and continue until the
pointers meet.

**Time Complexity:** O(n)

**Space Complexity:** O(1)
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n - 1;
        int ans = 0;
        int lmax = 0, rmax = 0;
        while (l < r) {
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);

            if (lmax < rmax) {
                ans += lmax - height[l];
                l++;
            } else {
                ans += rmax - height[r];
                r--;
            }
        }
        return ans;
    }
};
