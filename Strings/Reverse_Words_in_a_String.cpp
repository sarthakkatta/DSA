/*
Problem: LeetCode 151 – Reverse Words in a String


Approach:
1. Reverse the entire string.
2. Traverse the string and extract each word.
3. Reverse the extracted word to correct its order.
4. Append words to result string with proper spacing.
5. Remove leading space before returning result.

Time Complexity: O(N)
Space Complexity: O(N)
*/


class Solution{
public:
    string reverseWords(string s){
        int n = s.length();
        string ans = "";
        reverse(s.begin(), s.end());
        for(int i = 0; i < n; i++){
            string word = "";
            while(i < n && s[i] != ' '){
                word += s[i];
                i++;
            }
            reverse(word.begin(), word.end());
            if(word.length() > 0){
                ans += " " + word;
            }
        }
        return ans.substr(1);
    }
};
