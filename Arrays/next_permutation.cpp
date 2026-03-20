/*
Problem: LeetCode 31 – Next Permutation

Approach:
1. Find the first decreasing element from the right (breakpoint).
2. If no such element exists, reverse the entire array.
3. Otherwise, find the element just greater than the breakpoint from the right and swap.
4. Reverse the suffix after the breakpoint to get the next permutation.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> nextPermutation(vector<int>& A) {
        int ind = -1;
        int n = A.size();
        // Step 1: Find the first decreasing element from the right(break point)
        for (int i = n - 2; i >= 0; i--) {
            if (A[i] < A[i + 1]) {
                ind = i;
                break;
            }
        }
        // If no such element is found, reverse the entire array (last permutation case)(mtlb agr for ex (5,4,3,2,1) yeh arr given h toh exp 2 dekh lena baaki aur)
        if (ind == -1) {
            reverse(A.begin(), A.end());
            return A;
        }
        // Step 2: Find the element just larger than A[ind] from the right and swap
        for (int i = n - 1; i > ind; i--) {
            if (A[i] > A[ind]) {
                swap(A[i], A[ind]);
                break;
            }
        }
        // Step 3: Reverse the suffix starting from ind + 1
        reverse(A.begin() + ind + 1, A.end());
        return A;
    }
};
