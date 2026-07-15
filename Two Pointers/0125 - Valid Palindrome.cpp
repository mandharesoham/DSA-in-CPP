/*
Problem: 125. Valid Palindrome
Platform: LeetCode
Difficulty: Easy

Tags:
- String
- Two Pointers

Time Complexity: O(n)
Space Complexity: O(1)

Approach:
Use two pointers, one starting from the beginning and the other from the end
of the string. Skip all non-alphanumeric characters and compare the remaining
characters after converting them to lowercase. If all corresponding characters
match, the string is a valid palindrome.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int st = 0, end = s.size() - 1;

        while (st < end) {
            if (!isalnum(s[st])) {
                st++;
                continue;
            }
            if (!isalnum(s[end])) {
                end--;
                continue;
            }
            if (tolower(s[st]) != tolower(s[end])) {
                return false;
            } else {
                st++;
                end--;
            }
        }
        return true;
    }
};
