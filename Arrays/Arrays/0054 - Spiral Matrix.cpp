/*
Problem: 54. Spiral Matrix
Platform: LeetCode
Difficulty: Medium

Tags:
- Array
- Matrix
- Simulation

Time Complexity: O(m × n)
Space Complexity: O(1)   // Excluding the output vector

Approach:
Maintain four boundaries:
- top
- bottom
- left
- right

Traverse the matrix in four directions:
1. Left to Right
2. Top to Bottom
3. Right to Left
4. Bottom to Top

After each traversal, update the corresponding boundary.
Repeat until all elements are visited.
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m=mat.size(); int n=mat[0].size();
        int srow=0,endrow=m-1,scol=0,endcol=n-1;
        vector<int> ans;
        while(srow<=endrow && scol<=endcol ){
            //top
            for(int i=scol;i<=endcol;i++){
                ans.push_back(mat[srow][i]);

            }
            //right
            for(int j=srow+1;j<=endrow;j++){
                ans.push_back(mat[j][endcol]);
            }
            //bottom
            for(int i=endcol-1;i>=scol;i--){
                if(srow==endrow){
                    break;
                }
                ans.push_back(mat[endrow][i]);
            }
            //left
            for(int j=endrow-1;j>=srow+1;j--){
                if(scol==endcol){
                    break;
                }
                ans.push_back(mat[j][scol]);
            }
            srow++; endrow--;
            scol++; endcol--;
        }
        return ans;
    }
};
