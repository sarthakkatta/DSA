/*
Problem: LeetCode 132 – Palindrome Partitioning II

Approach:
1. Try all possible partitions from index i.
2. If substring is palindrome → take partition.
3. dp[i] → minimum partitions from index i to end.
4. Compute minimum among all valid partitions.
5. Subtract 1 at end to get minimum cuts.

Time Complexity: O(N * N)
Space Complexity:
Memoization → O(N)
Tabulation → O(N)
*/


// ======================= MEMOIZATION =======================

class Solution {
public:

    bool isPalindrome(int i,
                      int j,
                      string &s) {

        while (i < j) {

            if (s[i] != s[j])
                return false;

            i++;
            j--;
        }

        return true;
    }


    int minPartitions(int i,
                      int n,
                      string &str,
                      vector<int> &dp) {

        if (i == n) return 0;

        if (dp[i] != -1)
            return dp[i];

        int minCost = INT_MAX;

        for (int j = i;
             j < n;
             j++) {

            if (isPalindrome(i, j, str)) {

                int cost =
                    1 + minPartitions(
                            j + 1,
                            n,
                            str,
                            dp);

                minCost =
                    min(minCost, cost);
            }
        }

        return dp[i] = minCost;
    }


    int minCut(string s) {

        int n = s.size();

        vector<int> dp(n, -1);

        return minPartitions(
            0, n, s, dp) - 1; // yeh last waale char ke bhi partition kr deta h isliye yaha ek -1 kiya h
    }
};



// ======================= TABULATION =======================

class Solution{
public:

    bool isPalindrome(int i,
                      int j,
                      string &s) {

        while (i < j) {

            if (s[i] != s[j])
                return false;

            i++;
            j--;
        }

        return true;
    }


    int minCut(string str) {

        int n = str.size();

        vector<int> dp(n + 1, 0);

        dp[n] = 0;

        for (int i = n - 1;
             i >= 0;
             i--) {

            int minCost = INT_MAX;

            for (int j = i;
                 j < n;
                 j++) {

                if (isPalindrome(i, j, str)) {

                    int cost =
                        1 + dp[j + 1];

                    minCost =
                        min(minCost, cost);
                }
            }

            dp[i] = minCost;
        }

        return dp[0] - 1;
    }
};
