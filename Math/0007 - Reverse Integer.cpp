/*
Problem: 7. Reverse Integer
Platform: LeetCode
Difficulty: Medium

Tags:
- Math
- Integer
- Overflow

Time Complexity: O(log₁₀n)
Space Complexity: O(1)

Approach:
Extract each digit using modulo (%10) and build the reversed number.
Before appending a digit, check for integer overflow and underflow.
If reversing the integer exceeds the 32-bit signed integer range,
return 0.
*/

class Solution {
public:
    int reverse(int x) {
        int revN=0;
        while(x!=0){
           int lastd=x%10;
            x=x/10;
            if(revN>INT_MAX/10 || (revN==INT_MAX/10 && lastd>7))
            return 0;
            if(revN<INT_MIN/10 || (revN==INT_MIN/10 && lastd<-8))
            return 0;

            revN=(revN*10)+lastd;
            
        }
        return revN;
        
    }
};
