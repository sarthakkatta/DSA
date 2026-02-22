/*
Problem: LeetCode 2220 – Minimum Bit Flips to Convert Number


Approach:
1. XOR start and goal to find differing bits.
2. Count number of set bits in XOR result.
3. Each set bit represents one required flip.
4. Return total count.

Time Complexity: O(1)
Space Complexity: O(1)
*/


class Solution{
public:
    int minBitFlips(int start, int goal){
        int ans = start ^ goal;
        int cnt = 0;
        for(int i = 0; i <= 31; i++){
            if(ans & (1 << i)) cnt++;
        }
        return cnt;
    }
};
