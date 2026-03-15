/*
Problem: Find Floor Square Root

Approach:
1. Use Binary Search in the range [1, n].
2. For each mid, compute mid * mid.
3. If mid*mid <= n, move right to find a larger possible square root.
4. Otherwise move left.
5. When the loop ends, high will store the floor value of sqrt(n).

Time Complexity: O(log N)
Space Complexity: O(1)
*/

int floorSqrt(int n)
{
    int low = 1, high = n;
    while(low <= high){
        long long mid = (low + high) / 2;
        long long val = mid * mid;
        if(val <= n){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return high;
}
