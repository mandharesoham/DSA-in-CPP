/*
Problem: 121. Best Time to Buy and Sell Stock
Platform: LeetCode
Difficulty: Easy

Tags:
- Array
- Greedy
- Dynamic Programming

Time Complexity: O(n)
Space Complexity: O(1)

Approach:
Traverse the array while keeping track of the minimum stock price seen so far.
For each day, calculate the profit by selling on that day and update the
maximum profit if it is greater than the current maximum.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int minprize=prices[0];
        int maxprofit=0;
        for(int i=1;i<n;i++){
            minprize=min(minprize,prices[i]);
            maxprofit=max(maxprofit,prices[i]-minprize);

        }
        return maxprofit;
        
    }
    
};
