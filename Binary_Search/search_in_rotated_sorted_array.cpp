/*
Problem: Search in Rotated Sorted Array

Approach:
1. Use Binary Search on the rotated sorted array.
2. At each step determine which half of the array is sorted.
3. If the left half is sorted, check if the target lies within it.
4. If the right half is sorted, check if the target lies within it.
5. Narrow the search space accordingly until the element is found.

Time Complexity: O(log N)
Space Complexity: O(1)
*/

class Solution {
public:
    int search(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == k) return mid;
            // Left part is sorted
            if (arr[low] <= arr[mid]) {
                if (arr[low] <= k && k < arr[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // Right part is sorted
            else {
                if (arr[mid] < k && k <= arr[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};
