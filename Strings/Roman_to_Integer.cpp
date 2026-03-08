/*
Problem: LeetCode 13 – Roman to Integer


Approach:
1. Store Roman numeral values in a lookup array for O(1) access.
2. Start from the last character and initialize result with its value.
3. Traverse the string from right to left.
4. If current value is less than next value, subtract it.
5. Otherwise add it.
6. Return the final result.

Time Complexity: O(N)
Space Complexity: O(1)
*/


class Solution{
public:
    int romanToInt(string s){
        int roman[128] = {};
        roman['I'] = 1; roman['V'] = 5; roman['X'] = 10; roman['L'] = 50;
        roman['C'] = 100; roman['D'] = 500; roman['M'] = 1000;

        int result = roman[s.back()];

        for(int i = s.length() - 2; i >= 0; i--){
            if(roman[s[i]] < roman[s[i+1]]){
                result -= roman[s[i]];
            }
            else{
                result += roman[s[i]];
            }
        }

        return result;
    }
};
