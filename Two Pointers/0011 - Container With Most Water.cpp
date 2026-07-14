/*
Problem: 11. Container With Most Water
Platform: LeetCode
Difficulty: Medium

Tags:
- Array
- Two Pointers
- Greedy

Time Complexity: O(n)
Space Complexity: O(1)

Approach:
Use two pointers, one at the beginning and one at the end of the array.
Calculate the area formed by the two lines and update the maximum area.
Move the pointer with the smaller height inward, as moving the taller
pointer cannot increase the area while the shorter height remains the
limiting factor.
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int mw = 0, lp = 0, rp = height.size() - 1;
        while (lp < rp) {
            int ht = min(height[lp], height[rp]);
            int w = rp - lp;
            int cw = ht * w;
            mw = max(mw, cw);
            height[lp] < height[rp] ? lp++ : rp--;
        }
        return mw;
    }
};
