/*
Problem:
---------
LeetCode 3438. Find Valid Pair of Adjacent Digits in String


Approach:
---------
We first count how many times each digit appears in the string using an
unordered_map.

The condition for a valid pair is:
- The two adjacent digits must be different.
- The frequency of the first digit must be exactly equal to its digit value.
- The frequency of the second digit must be exactly equal to its digit value.

After building the frequency map, we traverse the string from left to right
and check every adjacent pair.

For each pair:
- `prev != curr` ensures both digits are different.
- `mpp[prev - '0'] == prev - '0'` checks whether the first digit appears
  exactly as many times as its numerical value.
- `mpp[curr - '0'] == curr - '0'` performs the same check for the second digit.

As soon as we find a valid pair, we add both characters to `res` and return it.

If no valid adjacent pair exists, we return the empty string.


Key Idea:
---------
The main idea is to separate the problem into two simple parts:

1. Count the frequency of every digit.
2. Check each adjacent pair using those frequencies.

For example, if digit `2` appears exactly 2 times and digit `3` appears
exactly 3 times, then the adjacent pair `"23"` is valid, provided the two
digits are different and occur next to each other.

Since we only need the first valid pair, we immediately return once we find
one.


Example:
--------
Suppose:
s = "252"

Frequency:
    2 -> 2 times
    5 -> 1 time

For pair "25":
    2 appears 2 times  -> valid
    5 appears 1 time   -> not valid

So "25" is not returned.

The algorithm continues checking the remaining adjacent pairs until it finds
a pair where both digits satisfy their frequency conditions.


Time Complexity:
----------------
O(n)

We make one pass to count digit frequencies and another pass to check
adjacent pairs. Since there are only 10 possible digits, the hashmap
operations are effectively O(1).


Space Complexity:
-----------------
O(1)

The unordered_map stores frequencies for digits from 0 to 9, so its size
is bounded by a constant.
*/

class Solution {

public:

    string findValidPair(string s) {

        unordered_map<int, int> mpp;

        for (auto &c : s) {

            mpp[c - '0']++;

        }

        string res = "";

        for (int i = 1; i < s.size(); i++) {

            char prev = s[i - 1];

            char curr = s[i];

            if (prev != curr && mpp[prev - '0'] == prev - '0' && mpp[curr - '0'] == curr - '0') {

                res += prev;

                res += curr;

                return res;

            }

        }

        return res;

    }

};
