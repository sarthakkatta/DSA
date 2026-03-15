/*
Problem: Find Largest Element in an Array

Approach:
1. Initialize the answer with the first element of the array.
2. Traverse the array and compare each element with the current maximum.
3. Update the maximum whenever a larger element is found.
4. Return the maximum element at the end.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int largest(vector<int> &arr) {
        int ans = arr[0];
        for(int i = 0; i < arr.size(); i++){
            if(ans < arr[i]) ans = arr[i];
        }
        return ans;
    }
};
