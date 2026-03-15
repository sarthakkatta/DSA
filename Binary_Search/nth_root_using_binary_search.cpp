/*
Problem: Find Nth Root of an Integer

Approach:
1. Use Binary Search on the range [1, m] to find the integer whose nth power equals m.
2. For each mid, compute mid^n using a loop.
3. If mid^n == m, return mid.
4. If mid^n < m, search in the right half.
5. If mid^n > m, search in the left half.
6. If no integer root exists, return -1.

Time Complexity: O(N log M)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int func(int mid, int n, int m) {
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = ans * mid;
        if (ans > m) return 2;
    }
    if (ans == m) return 1;
    return 0;
}

int NthRoot(int n, int m) {
    int low = 1, high = m;
    while (low <= high) {
        int mid = (low + high) / 2;
        int midN = func(mid, n, m);
        if (midN == 1) {
            return mid;
        }
        else if (midN == 0) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
