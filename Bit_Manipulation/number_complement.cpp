/*
Problem: LeetCode 476 – Number Complement

Approach:
1. Create a mask with all bits set to 1.
2. Shift the mask left until it no longer overlaps with num.
3. Invert both mask and num.
4. AND them to get the complement within valid bit range.

Time Complexity: O(log N)
Space Complexity: O(1)
*/

class Solution {
public:
    int findComplement(int num) {
        if (num == 0) return 1;
        
        unsigned int mask = ~0;
        
        while (num & mask) {
            mask <<= 1;
        }
        
        return ~mask & ~num;
    }
};
