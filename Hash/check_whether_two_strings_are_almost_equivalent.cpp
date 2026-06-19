/*
Problem: LeetCode 2068 – Check Whether Two Strings are Almost Equivalent

Approach:
1. Create a frequency array of size 26.
2. Traverse both strings simultaneously:
   - Increase count for characters in word1.
   - Decrease count for characters in word2.
3. After traversal:
   - freq[i] stores frequency difference of
     the i-th character between the two strings.
4. Check every character:
   - If absolute difference > 3:
       → Strings are not almost equivalent.
       → Return false.
5. If all differences are within 3:
   - Return true.

Key Idea:
- Two strings are almost equivalent if the
  frequency difference of every character
  does not exceed 3.

Time Complexity: O(N + 26) ≈ O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int> map(26, 0);

        for (int i = 0; i < word1.length(); i++) {
            map[word1[i] - 'a']++;
            map[word2[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (abs(map[i]) > 3) {
                return false;
            }
        }

        return true;
    }
};
