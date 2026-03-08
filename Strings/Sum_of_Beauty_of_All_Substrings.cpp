/*
Problem: LeetCode 1781 – Sum of Beauty of All Substrings

Approach:
1. Iterate through all possible starting indices.
2. Maintain a frequency array for characters.
3. Expand substring and update character frequency.
4. Compute max and min frequency (excluding zero).
5. Add (maxfreq - minfreq) to total beauty.

Time Complexity: O(N^2 * 26)
Space Complexity: O(26)
*/

class Solution{
public:
    int beautySum(string s){
        int total_beauty = 0;
        for(int i = 0; i < s.length(); i++){
            vector<int> freq(26, 0);
            for(int j = i; j < s.length(); j++){
                freq[s[j] - 'a']++;
                int maxfreq = 0, minfreq = INT_MAX;
                for(int f : freq){
                    if(f > 0){
                        maxfreq = max(maxfreq, f);
                        minfreq = min(minfreq, f);
                    }
                }
                total_beauty += (maxfreq - minfreq);
            }
        }
        return total_beauty;
    }
};
