/*
Problem: Leaders in an Array

Approach:
1. Traverse the array from right to left.
2. Keep track of the maximum element seen so far.
3. If the current element is greater than or equal to the maximum, it is a leader.
4. Add such elements to the result.
5. Reverse the result to maintain original order.

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    vector<int> leaders(vector<int>& arr) {
        vector<int> res;
        int n = arr.size();
        int max = INT_MIN;
        for(int i = n - 1; i >= 0; i--){
            if(arr[i] >= max){
                res.push_back(arr[i]);
                max = arr[i];
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
