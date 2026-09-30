/*
Problem:
---------
LeetCode 3271 - Hash Divided String


Approach:
---------
We need to divide the string into groups of size `k` and generate one
character for each group.

The string is processed in chunks:
    [first k characters]
    [next k characters]
    [next k characters]
    ...

For every group, we calculate the sum of the values of its characters.

Each lowercase character is converted into a value from 0 to 25:

    'a' -> 0
    'b' -> 1
    'c' -> 2
    ...
    'z' -> 25

This is done using:

    s[j] - 'a'

After calculating the sum of one group, we use:

    sum % 26

This keeps the resulting value between 0 and 25, which corresponds to
one of the 26 lowercase English letters.

Finally, we convert that value back into a character by adding `'a'` and
append it to the answer string.


Key Idea:
---------
The main idea is:

1. Divide the string into groups of size `k`.
2. Convert every character in a group into a number from 0 to 25.
3. Add all those values.
4. Take the sum modulo 26.
5. Convert the resulting value back into a character.
6. Store that character in the answer.

The `% 26` is important because there are exactly 26 lowercase English
letters.

For example, if the sum is `27`:

    27 % 26 = 1

And value `1` corresponds to:

    'b'


Example:
--------
Suppose:

    s = "abcd"
    k = 2

Groups:

    "ab"
    "cd"

For "ab":

    'a' -> 0
    'b' -> 1

    sum = 0 + 1 = 1

    1 % 26 = 1
    1 + 'a' = 'b'

So the first character of the answer is `'b'`.

For "cd":

    'c' -> 2
    'd' -> 3

    sum = 2 + 3 = 5

    5 % 26 = 5
    5 + 'a' = 'f'

Therefore:

    ans = "bf"


Time Complexity:
----------------
O(n)

Every character of the string is processed exactly once by the nested
loops.

The outer loop processes groups, while the inner loop processes the
characters inside each group.


Space Complexity:
-----------------
O(n)

The answer string stores one character for every group. In the worst case,
when `k = 1`, the answer can contain `n` characters.
*/

class Solution {

public:

    string stringHash(string s, int k) {

        int n = s.size();

        string ans = "";

        for (int i = 0; i < n; i += k) {

            int sum = 0;

            for (int j = i; j < i + k; j++) {

                sum += s[j] - 'a';

            }

            ans += char(sum % 26 + 'a');

        }

        return ans;

    }

};
