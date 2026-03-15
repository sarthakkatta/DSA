/*
Problem: LeetCode 540 – Single Element in a Sorted Array

Approach:
1. Use Binary Search on the sorted array where every element appears twice except one.
2. Handle edge cases where the single element is at the beginning or end.
3. For each mid, check if it differs from its neighbors; if yes, it is the answer.
4. Use the index parity property:
   - Before the single element, pairs start at even indices.
   - After the single element, pairs start at odd indices.
5. Adjust the search space based on this pattern.

Time Complexity: O(log N)
Space Complexity: O(1)
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];
        if (arr[0] != arr[1]) return arr[0];
        if (arr[n - 1] != arr[n - 2]) return arr[n - 1];
        int low = 1, high = n - 2;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) {
                return arr[mid];
            }
            if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
};
