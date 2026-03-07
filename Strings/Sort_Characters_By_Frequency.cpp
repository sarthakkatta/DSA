/*
Problem: LeetCode 451 – Sort Characters By Frequency


Approach:
1. Count frequency of each character using hashmap.
2. Store pairs of (frequency, character).
3. Sort pairs in descending order of frequency.
4. Append each character frequency times to result string.
5. Return the final string.

Time Complexity: O(N log N)
Space Complexity: O(N)
*/


class Solution{
public:
    string frequencySort(string s){
        unordered_map<char,int> freq;

        for(char c : s){
            freq[c]++;
        }

        vector<pair<int,char>> hash;

        for(auto &p : freq){
            hash.push_back({p.second, p.first});
        }

        sort(hash.begin(), hash.end(), [](auto &a, auto &b){
            return a.first > b.first;
        });

        string res = "";

        for(auto &p : hash){
            res.append(p.first, p.second);
        }

        return res;
    }
};
