/*
Problem: 151. Reverse Words in a String
Platform: LeetCode
Difficulty: Medium

Tags:
- String
- Two Pointers

Time Complexity: O(n)
Space Complexity: O(1)   // If solved in-place

Approach:
Traverse the string while extracting each word and ignoring extra spaces.
Store or rearrange the words in reverse order, ensuring that only a single
space separates adjacent words and that there are no leading or trailing spaces.
*/

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";
        reverse(s.begin(), s.end());
        for (int i = 0; i < n; i++) {
            string word = "";
            while (i < n && s[i] != ' ') {
                word = word + s[i];
                i++;
            }
            reverse(word.begin(), word.end());
            if(word.size()>0){
                ans+=" "+word;

            }
        }
        return ans.substr(1);
    }
};
