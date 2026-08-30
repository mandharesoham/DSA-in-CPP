/*### 387. First Unique Character in a String

- **Difficulty:** Easy
- **Topics:** String, Hash Table, Queue

**Explanation:**
Use an `unordered_map` to store the frequency of each character
and a queue to store the indices of characters that are currently
unique.

While traversing the string, add the index of a character to the
queue when it appears for the first time. After updating its
frequency, remove indices from the front of the queue whenever
their character appears more than once.

The front of the queue always represents the first unique
character. If the queue is empty, return `-1`.

**Time Complexity:** O(n)

**Space Complexity:** O(n)
*/

class Solution {
public:
    int firstUniqChar(string s) {
        
        unordered_map<char, int> m;
        queue<int> q;

        for (int i = 0; i < s.size(); i++) {
            if (m.find(s[i]) == m.end()) {
                q.push(i);
            }
            m[s[i]]++;

            while (q.size() > 0 && m[s[q.front()]] > 1) {
                q.pop();
            }
        }
        return q.empty() ? -1 : q.front();
    }
};
