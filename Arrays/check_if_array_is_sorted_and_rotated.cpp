/*
Problem: LeetCode 1752 – Check if Array Is Sorted and Rotated

Approach:
1. Traverse the array and count the number of positions where the order breaks (nums[i-1] > nums[i]).
2. If the array is sorted and rotated, there should be at most one such break.
3. Also check the last and first elements to handle rotation.
4. If the count of breaks is more than 1, the array is not sorted and rotated.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){
                cnt++;
            }
        }
        if(nums[n-1]>nums[0]){
            cnt++;
        }
        return cnt<=1;
    }
};
