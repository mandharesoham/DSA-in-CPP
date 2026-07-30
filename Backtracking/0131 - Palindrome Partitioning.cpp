/*
Problem: 131. Palindrome Partitioning
Platform: LeetCode
Difficulty: Medium

Tags:
- String
- Backtracking
- Recursion

Time Complexity: O(n × 2^n)
Space Complexity: O(n)

Approach:
Use backtracking to generate all possible partitions of the string.
At each position, consider every possible substring.
If the substring is a palindrome, add it to the current partition
and recursively partition the remaining string.
Backtrack by removing the last added substring and continue exploring.
*/

class Solution {
public:
    bool isPalindrome(string s) {

        string s2 = s;
        reverse(s.begin(), s.end());
        return s2 == s;
    }

    void getAllPalindrome(string s, vector<vector<string>>& ans,
                          vector<string>& partitions) {
        if (s.size() == 0) {
            ans.push_back(partitions);
            return;
        }
        for (int i = 0; i < s.size(); i++) {
            string part = s.substr(0, i + 1);
            if (isPalindrome(part)) {
                partitions.push_back(part);
                getAllPalindrome(s.substr(i + 1), ans, partitions);
                partitions.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partitions;

        getAllPalindrome(s, ans, partitions);
        return ans;
    }
};
