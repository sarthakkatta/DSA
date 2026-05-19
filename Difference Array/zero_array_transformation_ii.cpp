/*
Problem: LeetCode 3356 – Zero Array Transformation II

Approach:
1. Goal:
   - Find minimum number of queries required to make all elements ≤ 0.
2. Use Binary Search on number of queries:
   - Search range: [0, Q-1]
3. Helper Function:
   - checkWithDifferenceArrayTeq(...)
   - Uses Difference Array to apply first k queries efficiently.
4. For each query:
   - Add x at left index
   - Subtract x after right index
5. Compute prefix sum:
   - Gives total decrement applied at each index.
6. If nums[i] - applied_value > 0:
   - Array cannot become zero → return false.
7. Binary search:
   - If possible with mid queries:
       → store answer and search smaller range.
   - Else:
       → search larger range.
8. Edge Case:
   - If array already all zero → return 0.

Key Idea:
- Difference Array handles range updates efficiently.
- Binary Search minimizes number of required queries.

Time Complexity: O(N log Q + Q log Q)
Space Complexity: O(N)
*/

class Solution {
public:
    int n;
    int Q;
    bool checkWithDifferenceArrayTeq(vector<int>& nums, vector<vector<int>>& queries, int k) {
        vector<int> diff(n, 0);
        for(int i = 0; i <= k; i++) {
            int l = queries[i][0];
            int r   = queries[i][1];
            int x     = queries[i][2];

            diff[l] += x;
            if(r+1 < n)
                diff[r+1] -= x;
        }

        int cumSum = 0;
        for(int i = 0; i < n; i++) {
            cumSum += diff[i];
            diff[i] = cumSum;
            if(nums[i] - diff[i] > 0) { //nums[i] 0 nahi ban paya
                return false;
            }
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        Q = queries.size();
        auto lambda = [](int x) {
            return x == 0;
        };
        if(all_of(begin(nums), end(nums), lambda)) {
            return 0; //no query required because all are already zero
        }
        int l = 0;
        int r = Q-1;
        int k = -1;
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(checkWithDifferenceArrayTeq(nums, queries, mid) == true) {
                k = mid+1; //possible answer
                r = mid-1;
            } else {
                 l = mid+1;
            }
        }
        return k;
    }
};
