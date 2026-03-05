/*
Problem: LeetCode 1903 – Largest Odd Number in String


Approach:
1. Traverse the string from right to left.
2. Check if the digit is odd.
3. If odd digit is found, return substring from start to that index.
4. If no odd digit exists, return empty string.

Time Complexity: O(N)
Space Complexity: O(1)
*/


class Solution{
public:
    string largestOddNumber(string num){
        for(int i = num.size() - 1; i >= 0; i--){
            if((num[i] - '0') % 2 != 0){
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};
