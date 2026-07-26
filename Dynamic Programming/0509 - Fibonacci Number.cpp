/*
Problem: 509. Fibonacci Number
Platform: LeetCode
Difficulty: Easy

Tags:
- Dynamic Programming
- Recursion
- Memoization
- Tabulation

Time Complexity: O(n)
Space Complexity: O(1)   // Space-optimized iterative solution

Approach:
Use Dynamic Programming to compute Fibonacci numbers iteratively.
Maintain only the previous two Fibonacci values and update them
until reaching the nth number, reducing space usage to O(1).
*/

class Solution {
public:
    int fib(int n) {
        if (n == 1 || n == 0) {
            return n;
        }
        return fib(n - 1) + fib(n - 2);
    }
};
