/*
Problem: 443. String Compression
Platform: LeetCode
Difficulty: Medium

Tags:
- String
- Two Pointers
- Array

Time Complexity: O(n)
Space Complexity: O(1)

Approach:
Use two pointers:
- One pointer reads consecutive groups of identical characters.
- Another pointer writes the compressed result back into the array.

For each group:
1. Write the character.
2. If its frequency is greater than 1, convert the count to a string
   and write each digit separately.

Return the length of the compressed array.
*/

class Solution {
public:
    int compress(vector<char>& chars) {
        int idx = 0;
        int n = chars.size();
        for (int i = 0; i < n; i++) {
            char ch = chars[i];
            int cnt = 0;
            while (i < n && ch == chars[i]) {
                cnt++;
                i++;
            }
            if (cnt == 1) {
                chars[idx] = ch;
                idx++;
            } else {
                chars[idx++] = ch;
                string str = to_string(cnt);
                for (char dig : str) {
                    chars[idx++] = dig;
                }
            }
            i--;
        }
        chars.resize(idx);
        return idx;
    }
};
