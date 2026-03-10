/*
Problem: LeetCode 5 – Longest Palindromic Substring

Approach:
1. Use Expand Around Center technique.
2. For every index i, check two cases:
   - Even length palindrome (center between i-1 and i).
   - Odd length palindrome (center at i).
3. Expand left and right while characters match.
4. Update start index and maximum length whenever a longer palindrome is found.
5. Return substring using start and maxLen.

Time Complexity: O(N^2)
Space Complexity: O(1)
*/

class Solution{
public:
    string longestPalindrome(string s){
        int start = 0, maxLen = 1;
        int n = s.size();

        for(int i = 1; i < n; i++){

            int l = i - 1, r = i;
            while(l >= 0 && r < n && s[l] == s[r]){
                if(r - l + 1 > maxLen){
                    maxLen = r - l + 1;
                    start = l;
                }
                l--;
                r++;
            }

            l = i - 1, r = i + 1;
            while(l >= 0 && r < n && s[l] == s[r]){
                if(r - l + 1 > maxLen){
                    maxLen = r - l + 1;
                    start = l;
                }
                l--;
                r++;
            }
        }

        return s.substr(start, maxLen);
    }
};
