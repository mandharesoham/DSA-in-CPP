/*
Problem: 169. Majority Element
Platform: LeetCode
Difficulty: Easy

Tags:
- Array
- Hash Table
- Boyer-Moore Voting Algorithm

Time Complexity: O(n)
Space Complexity: O(1)

Approach:
Use Boyer-Moore Voting Algorithm to find the majority element.
Maintain a candidate and a counter. Increase the counter when the current
element matches the candidate; otherwise, decrease it. If the counter
becomes zero, choose the current element as the new candidate.
Since the majority element appears more than n/2 times, the final candidate
is the answer.
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq=0,ans=0;
        for(int i=0;i<nums.size();i++){
            if(freq==0){
                ans=nums[i];
            }
            if(ans==nums[i]){
                freq++;
            }
            else freq--;
        }
        return ans;
        
    }
};
