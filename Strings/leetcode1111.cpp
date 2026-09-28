/*
Problem:
---------
LeetCode 1111 - Maximum Nesting Depth of Two Valid Parentheses Strings

Approach:
---------
1. We need to split the given valid parentheses sequence into two
   subsequences such that the maximum nesting depth of both subsequences
   is minimized.

2. Maintain `curr`:
   - It represents the current nesting depth of the original sequence.

3. Traverse the sequence character by character.

4. When we encounter `(`:
   - Increase the current depth:

       curr++

   - Assign the parenthesis to group:

       curr % 2

5. When we encounter `)`:
   - The closing parenthesis belongs to the same depth level as the
     corresponding opening parenthesis.
   - Therefore, first assign:

       curr % 2

   - Then decrease the current depth:

       curr--

6. The result contains either 0 or 1 for every parenthesis:
   - `0` -> first subsequence
   - `1` -> second subsequence

7. Using alternating depth levels distributes nested parentheses
   between the two groups.

Key Idea:
---------
The important observation is that we can divide parentheses based on
the parity of their nesting depth.

For example, if the nesting depths are:

    1 -> group 1
    2 -> group 0
    3 -> group 1
    4 -> group 0

Then deeply nested parentheses are distributed between the two
subsequences.

This keeps the maximum depth of both subsequences balanced.

The expression:

    curr % 2

automatically alternates between the two groups.

Example:
--------
seq = "(()())"

Process:

    ( -> curr = 1 -> ans = 1
    ( -> curr = 2 -> ans = 0
    ) -> curr = 2 -> ans = 0
    ( -> curr = 2 -> ans = 0
    ) -> curr = 2 -> ans = 0
    ) -> curr = 1 -> ans = 1

Result:

    [1, 0, 0, 0, 0, 1]

So the parentheses are divided between the two subsequences according
to their nesting depth.

Example 2:
----------
seq = "((()))"

The nesting depths are:

    1
    2
    3

They are assigned alternately:

    depth 1 -> group 1
    depth 2 -> group 0
    depth 3 -> group 1

Therefore, neither subsequence contains the complete depth of 3.

Time Complexity:
----------------
O(n)

We traverse the sequence exactly once.

Space Complexity:
-----------------
O(n)

The answer vector contains one value for every character in the
sequence.
*/

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int curr = 0;
        vector<int> ans(seq.length());
        for (int i = 0; i < seq.length(); i++) {
            if (seq[i] == '(') {
                curr++;
                ans[i] = curr % 2;
            } else {
                ans[i] = curr % 2;
                curr--;
            }
        }

        return ans;
    }
};
