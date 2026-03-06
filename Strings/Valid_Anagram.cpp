/*
Problem: LeetCode 242 – Valid Anagram


Approach:
1. If lengths of both strings are different, they cannot be anagrams.
2. Use a frequency array of size 26 for lowercase letters.
3. Increase count for characters in string s.
4. Decrease count for characters in string t.
5. If all counts become zero, the strings are anagrams.

Time Complexity: O(N)
Space Complexity: O(1)
*/


class Solution{
public:
    bool isAnagram(string s, string t){
        if(s.length() != t.length()) return false;

        int count[26] = {0};

        for(int i = 0; i < s.size(); i++){
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for(int i = 0; i < 26; i++){
            if(count[i] != 0){
                return false;
            }
        }

        return true;
    }
};
