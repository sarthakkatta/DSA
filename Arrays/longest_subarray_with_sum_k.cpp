/*
Problem: Longest Subarray with Sum K

Approach:
1. Use Sliding Window (Two Pointers) since all elements are non-negative.
2. Maintain a window with pointers left and right and keep track of the sum.
3. If sum exceeds k, shrink the window from the left.
4. If sum equals k, update the maximum length.
5. Expand the window by moving right pointer.

Time Complexity: O(N)
Space Complexity: O(1)
*/

int longestSubarrayWithSumK(vector<int> a, long long k) {
    int left = 0, right = 0;
    long long sum = a[0];
    int maxLen = 0;
    int n = a.size();
    while(right < n){
        while(left <= right && sum > k){
            sum -= a[left];
            left++;
        }
        if(sum == k){
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if(right < n) sum += a[right];
    }
    return maxLen;
}
