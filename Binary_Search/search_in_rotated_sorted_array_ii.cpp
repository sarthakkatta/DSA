/*
Problem: Search in Rotated Sorted Array II

Approach:
1. Use Binary Search to search in the rotated array.
2. If the middle element equals the target, return true.
3. If duplicates appear at low, mid, and high, shrink the search space.
4. Determine which half of the array is sorted.
5. Check if the target lies within the sorted half and adjust the search range accordingly.

Time Complexity: O(log N) on average, O(N) in worst case due to duplicates
Space Complexity: O(1)
*/

class Solution {
public:
    bool search(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (arr[mid] == k) return true;

            // Handle duplicates
            if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
                low++;
                high--;
                continue;
            }

            // Left part sorted
            if (arr[low] <= arr[mid]) {
                if (arr[low] <= k && k < arr[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // Right part sorted
            else {
                if (arr[mid] < k && k <= arr[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};
