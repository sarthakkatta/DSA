/*
Problem: LeetCode 88 – Merge Sorted Array

Approach:
1. Use three pointers:
   - i → last valid element in nums1 (m - 1)
   - j → last element in nums2 (n - 1)
   - k → last index of nums1 (m + n - 1)
2. Compare elements from the back:
   - Place the larger element at position k.
   - Move pointers accordingly.
3. Continue until either array is exhausted.
4. If nums2 still has elements left, copy them into nums1.
5. No need to handle remaining nums1 elements as they are already in place.

Time Complexity: O(m + n)
Space Complexity: O(1)
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;  // Last valid element in nums1
        int j = n - 1;  // Last element in nums2
        int k = m + n - 1; // Last position in nums1 (total size)

        // Merge from back
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        // If nums2 has remaining elements
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};
