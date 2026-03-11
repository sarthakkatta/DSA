/*
Problem: LeetCode 500 – Keyboard Row

Approach:
1. Store the three keyboard rows as strings.
2. For each word, convert it to lowercase.
3. Determine which row the first character belongs to.
4. Check if all characters of the word belong to the same row.
5. If valid, add the word to the result.
*/

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        string firstr = "qwertyuiop";
        string secondr = "asdfghjkl";
        string thirdr = "zxcvbnm";

        for(int i = 0; i < words.size(); i++){
            string word = words[i];
            string temp = word;

            for(char &c : temp){
                c = tolower(c);
            }

            string row;
            if(firstr.find(temp[0]) != string::npos) row = firstr;
            else if(secondr.find(temp[0]) != string::npos) row = secondr;
            else row = thirdr;

            bool valid = true;
            for(char c : temp){
                if(row.find(c) == string::npos){
                    valid = false;
                    break;
                }
            }

            if(valid) ans.push_back(word);
        }

        return ans;
    }
};
