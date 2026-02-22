/*
Problem: XOR of Numbers in Given Range


Approach:
1. XOR from 0 to n follows pattern based on n % 4:
   - n % 4 == 0 → result = n
   - n % 4 == 1 → result = 1
   - n % 4 == 2 → result = n + 1
   - n % 4 == 3 → result = 0
2. XOR of range [L, R] = xorUpto(R) ^ xorUpto(L - 1).
3. This works because common prefix cancels out.

Time Complexity: O(1)
Space Complexity: O(1)
*/


int xorUpto(int n){
    if(n % 4 == 0) return n;
    else if(n % 4 == 1) return 1;
    else if(n % 4 == 2) return n + 1;
    else return 0;
}

int xorInRange(int L, int R){
    return xorUpto(R) ^ xorUpto(L - 1);
}
