/*
Problem: 50. Pow(x, n)
Platform: LeetCode
Difficulty: Medium

Tags:
- Math
- Recursion
- Binary Exponentiation

Time Complexity: O(log n)
Space Complexity: O(1)   // Iterative solution

Approach:
Use Binary Exponentiation (Fast Power).
Repeatedly square the base and halve the exponent.
If the current exponent is odd, multiply the answer by the current base.
Handle negative exponents by taking the reciprocal.
Use long long for the exponent to safely handle INT_MIN.
*/

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1.0;
        if (x == 0)
            return 0.0;
        if (x == 1)
            return 1.0;
        if (x == -1 && n % 2 == 0)
            return 1.0;
        if (x == -1 && n % 2 != 0)
            return -1.0;

        long binNUM = n;
        double ans = 1;
        if (n < 0) {
            x = 1 / x;
            binNUM = -binNUM;
        }
        while (binNUM > 0) {
            if (binNUM % 2 == 1) {
                ans *= x;
            }
            x *= x;
            binNUM /= 2;
        }
        return ans;
    }
};
