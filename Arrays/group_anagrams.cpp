/*
Problem: LeetCode 49 – Group Anagrams

Approach:
1. Use a hashmap:
   - Key → sorted version of string
   - Value → list of anagrams
2. For each string:
   - Sort its characters → this becomes the key.
   - Insert original string into map[key].
3. After processing all strings:
   - Extract all values from hashmap into result.
4. Return grouped anagrams.

Key Idea:
- Anagrams have same sorted string.

Time Complexity: O(N * K log K)
  (N = number of strings, K = max length of string)
Space Complexity: O(N)
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for(auto x: strs){
            string word = x;
            sort(word.begin(), word.end());
            mp[word].push_back(x);
        }
        vector<vector<string>> ans;
        for(auto x: mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};
