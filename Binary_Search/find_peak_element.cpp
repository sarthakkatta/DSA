/*
Problem: LeetCode 162 – Find Peak Element

Approach:
1. Use Binary Search to locate a peak element.
2. Handle edge cases where the peak may be at the beginning or end.
3. Check if the middle element is greater than both neighbors.
4. If the slope is increasing (arr[mid] > arr[mid-1]), move to the right half.
5. Otherwise move to the left half.
6. Continue until a peak element index is found.

Time Complexity: O(log N)
Space Complexity: O(1)
*/

class Solution {
public:
    int findPeakElement(vector<int> &arr) {
        int n = arr.size();
        if (n == 1) return 0;
        if (arr[0] > arr[1]) return 0;
        if (arr[n-1] > arr[n-2]) return n-1;
        int low = 1, high = n-2;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) {
                return mid;
            }
            else if (arr[mid] > arr[mid-1]) 
                low = mid + 1;
            else 
                high = mid - 1;
        }
        return -1;
    }
};
