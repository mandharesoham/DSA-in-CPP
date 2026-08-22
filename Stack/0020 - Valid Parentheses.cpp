/*
Problem: 20. Valid Parentheses
Platform: LeetCode
Difficulty: Easy

Topics:
- Stack
- String

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    bool isValid(string str) {
        stack<char> st;

        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(' || str[i] == '{' ||
                str[i] == '[') { // if it is opening bracket
                st.push(str[i]);
            } else { // if it is closing bracket
                if (st.size() == 0) {
                    return false;
                }

                if ((st.top() == '(' && str[i] == ')') ||
                    (st.top() == '[' && str[i] == ']') ||
                    (st.top() == '{' && str[i] == '}')) {
                    st.pop();
                } else { // no match
                    return false;
                }
            }
        }
        return st.size() == 0;
    }
};
