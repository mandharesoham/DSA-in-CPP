/*
Problem: 852. Peak Index in a Mountain Array
Platform: LeetCode
Difficulty: Medium

Tags:
- Array
- Binary Search

Time Complexity: O(log n)
Space Complexity: O(1)

Approach:
Use binary search to find the peak element by comparing nums[mid] with nums[mid + 1].
If nums[mid] < nums[mid + 1], move right; otherwise, move left.
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st=1,end=arr.size()-1;
        while(st<=end){
           int mid=st+(end-st)/2;
            if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]) return mid;

            if(arr[mid-1]<arr[mid]){//right search
                st=mid+1;
            }else{   // left search
                end=mid-1;
            }
        }
        return -1;
    }
};
