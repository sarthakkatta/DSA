/*
Problem:
---------
LeetCode 1492 - The kth Factor of n


Approach:
---------
We need to find the kth smallest factor of `n`.

First, we create a vector called `divisors` to store all the factors of
`n` except `n` itself.

We iterate from `1` to `n / 2`:
- If `n % i == 0`, then `i` is a factor of `n`.
- We add that factor to the `divisors` vector.

After collecting all possible factors smaller than `n`, we sort the vector
to make sure the factors are arranged in increasing order.

Then, we add `n` itself because `n` is also a factor of itself.

Now the vector contains all factors of `n` in sorted order.

Since arrays are zero-indexed, the kth factor is present at index `k - 1`.

If `k` is greater than the total number of factors, there is no kth factor,
so we return `-1`.

Otherwise, we traverse the sorted vector and store the factor whose index
is `k - 1` in `ans`.


Key Idea:
---------
The main idea is to generate all factors, sort them, and then directly
select the kth factor.

For example, if:

    n = 12

The factors are:

    1, 2, 3, 4, 6, 12

So:
    1st factor = 1
    2nd factor = 2
    3rd factor = 3
    4th factor = 4
    5th factor = 6
    6th factor = 12

Therefore, if `k = 3`, the answer is `3`.

The condition:

    if(i == k - 1)

is used because the vector uses zero-based indexing while `k` starts
from 1.


Example:
--------
Input:
n = 12
k = 5

Factors:
    1, 2, 3, 4, 6, 12

The 5th factor is:
    6

Therefore:
    ans = 6

If:

n = 7
k = 3

Factors:
    1, 7

There are only 2 factors, so the 3rd factor does not exist.

Therefore:
    ans = -1


Time Complexity:
----------------
O(n + d log d)

We iterate up to `n / 2` to find the factors, which takes O(n) time.

If `d` is the number of factors found, sorting them takes O(d log d).

Overall:
    O(n + d log d)


Space Complexity:
-----------------
O(d)

The vector stores all the factors of `n`, where `d` is the number of
factors.
*/

class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> divisors;
        for(int i = 1; i <= n / 2; i++){
            if(n % i == 0)divisors.push_back(i);
        }
        sort(divisors.begin(), divisors.end());
        divisors.push_back(n);
        int ans = 0;
        if(k > divisors.size()) ans = -1;
        for(int i = 0; i < divisors.size(); i++){
            if(i == k - 1) ans = divisors[i];
        }
        return ans;
    }
};
