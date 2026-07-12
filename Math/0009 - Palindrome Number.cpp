/*
Problem: 9. Palindrome Number
Platform: LeetCode
Difficulty: Easy

Tags:
- Math
- Integer
- Palindrome

Time Complexity: O(log₁₀n)
Space Complexity: O(1)

Approach:
Negative numbers cannot be palindromes.
Reverse the digits of the number and compare the reversed value
with the original number. If both are equal, the number is a palindrome.
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        int dub=x;
        int revd=0;
        while(x!=0){
            int lastd=x%10;
            x=x/10;
            if(revd>INT_MAX/10 || revd<INT_MIN/10)return false;
            revd=revd*10+lastd;
            
        }
       
        return revd==dub;
    }
};
