/*
Problem: LeetCode 3355 – Zero Array Transformation I

Approach:
1. Use Difference Array technique to track query coverage.
2. For each query [left, right]:
   - Increment diff[left]
   - Decrement diff[right + 1] (if within bounds)
3. Traverse array while maintaining prefix sum `coverage`:
   - coverage represents total operations available at index i.
4. If coverage < nums[i]:
   - Not enough operations to reduce nums[i] to zero
   - Return false.
5. If all indices are covered sufficiently → return true.

Key Idea:
- Difference array efficiently handles range increment operations.

Time Complexity: O(N + Q)
Space Complexity: O(N)
*/

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
       int n = nums.size();
       vector<int> diff(n+1,0);
       for(auto q : queries){
        int left = q[0];
        int right = q[1];

        diff[left]++;
        if(right + 1 < n){
            diff[right + 1]--;
        }
       }
       int coverage = 0;
       for(int i = 0; i < nums.size();i++){
           coverage += diff[i];

           if(coverage < nums[i]){
            return false;
           }
       } 
       return true;
    }
};
