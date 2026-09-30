/*
Problem:
---------
LeetCode 507 - Perfect Number


Approach:
---------
We need to determine whether the given number is a perfect number.

A perfect number is a positive integer that is equal to the sum of all its
positive divisors excluding itself.

We initialize `sum = 0` to store the sum of all proper divisors.

Then, we iterate from `1` to `num / 2`.

Why `num / 2`?
---------------
For any positive number `num`, no proper divisor other than `num` itself
can be greater than `num / 2`.

For every value of `i`:
- If `num % i == 0`, then `i` is a divisor of `num`.
- We add `i` to `sum`.

Finally, we check whether `sum == num`.
- If true, the number is perfect.
- Otherwise, it is not a perfect number.


Key Idea:
---------
The key idea is to find all proper divisors of the number and calculate
their sum.

For example, the divisors of `6` excluding `6` itself are:

    1, 2, 3

Their sum is:

    1 + 2 + 3 = 6

Since the sum is equal to the original number, `6` is a perfect number.


Example:
--------
Input:
num = 28

Proper divisors:
    1, 2, 4, 7, 14

Sum:
    1 + 2 + 4 + 7 + 14 = 28

Therefore:
    28 is a perfect number.

For a number like `10`:

Proper divisors:
    1, 2, 5

Sum:
    1 + 2 + 5 = 8

Since:
    8 != 10

Therefore, `10` is not a perfect number.


Time Complexity:
----------------
O(n)

We iterate from `1` to `num / 2`, which is approximately `n / 2`
iterations. Therefore, the overall complexity is O(n).


Space Complexity:
-----------------
O(1)

Only a single variable `sum` and the loop variable `i` are used, so no
extra space depending on the input size is required.
*/

class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        for(int i = 1; i <= num/2; i++){
            if(num % i == 0)sum += i;

        }
        return sum == num;
    }

};
