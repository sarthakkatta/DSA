/*
Problem: LeetCode 1299 – Replace Elements with Greatest Element on Right Side

Approach:
1. Traverse array from right to left.
2. Maintain variable `max_element` to track maximum seen so far on right.
3. For each index i:
   - Store current value.
   - Replace arr[i] with max_element.
   - Update max_element = max(max_element, current value).
4. Return modified array.

Key Idea:
- Right-to-left traversal allows tracking max efficiently.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int max_element = -1;
        for (int i = n - 1; i >= 0; i--) {
            int current_val = arr[i];
            arr[i] = max_element;
            max_element = max(max_element, current_val);
        }
        return arr;
    }
};
