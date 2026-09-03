/*### 134. Gas Station
- Difficulty: Medium
- Topics: Array, Greedy

- Explanation: First calculate the total amount of gas and total cost to check whether completing the circuit is possible. While traversing the stations, maintain `currGas` as the current fuel balance. If `currGas` becomes negative, the current starting station cannot be the answer, so set `start = i + 1` and reset `currGas` to 0. If total gas is less than total cost, return -1; otherwise, return the calculated starting station.

- Time: O(n)
- Space: O(1)
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas=0, totalCost=0;

        // unique soln always exits
        int currGas = 0, start = 0;
        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            currGas += (gas[i] - cost[i]);

            if (currGas < 0) {
                start = i + 1;
                currGas = 0;
            }
        }
        return totalGas < totalCost ? -1 : start;
    }
};
