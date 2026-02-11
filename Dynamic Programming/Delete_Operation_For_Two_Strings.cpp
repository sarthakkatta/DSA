/*
Problem: LeetCode 583 – Delete Operation for Two Strings

Approach:
1. Find Longest Common Subsequence (LCS) of both strings.
2. Characters not part of LCS must be deleted.
3. Minimum deletions = (length of word1 - LCS) + (length of word2 - LCS).
4. This simplifies to:
      word1.size() + word2.size() - 2 * LCS
5. Use space optimized LCS DP.

Time Complexity: O(N * M)
Space Complexity: O(M)
*/

class Solution {
public:

int lcs(string s, string t) {
    int n = s.size();
    int m = t.size();

    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s[i-1] == t[j-1]) {
                curr[j] = 1 + prev[j-1];
            } else {
                curr[j] = max(prev[j], curr[j-1]);
            }
        }
        prev = curr;
    }

    return prev[m];
}

int minDistance(string word1, string word2) {
    return word1.size() + word2.size() - 2*lcs(word1, word2); 
}

};
