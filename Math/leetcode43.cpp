/*
Problem:
---------
LeetCode 43 - Multiply Strings


Approach:
---------
We cannot directly convert the given strings into integers because the
numbers can be too large to fit into standard integer data types.

So, we perform multiplication manually, similar to how multiplication
is done on paper.

We create a result array of size `n + m`, where `n` and `m` are the
lengths of the two input strings.

For every digit of `num1` and every digit of `num2`:
- Convert both characters into integer digits.
- Multiply the two digits.
- Add the multiplication result to the existing value at the correct
  position in the result array.
- Store the current digit using `% 10`.
- Move the carry to the position on the left using `/ 10`.

The indices `i + j + 1` and `i + j` are used because the multiplication
of two digits contributes to two adjacent positions:
- `i + j + 1` stores the current digit.
- `i + j` receives the carry.

Finally, we traverse the result array and construct the answer string,
while skipping leading zeroes.


Key Idea:
---------
The main idea is to simulate normal multiplication using an integer
array.

For digits at positions `i` and `j`:

    num1[i] * num2[j]

contributes to the result positions around:

    i + j
    i + j + 1

The expression:

    sum = mul + res[i + j + 1]

combines the newly calculated multiplication value with any value that
was already present at that position.

Then:

    res[i + j + 1] = sum % 10

keeps only the current digit, while:

    res[i + j] += sum / 10

moves the carry to the left.

This allows us to multiply arbitrarily large numbers without converting
the entire strings into integers.


Example:
--------
Input:
num1 = "123"
num2 = "45"

The multiplication is equivalent to:

        123
      ×  45
      -----
        615
       492
      -----
       5535

The result array stores the individual digits and carries during the
digit-by-digit multiplication.

Final answer:
    "5535"


Time Complexity:
----------------
O(n × m)

Every digit of `num1` is multiplied with every digit of `num2`.


Space Complexity:
-----------------
O(n + m)

The result array contains at most `n + m` positions, where `n` and `m`
are the lengths of the two input strings.
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int n = num1.size();
        int m = num2.size();
        vector<int> res(n + m, 0);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int a = num1[i] - '0';
                int b = num2[j] - '0';
                int mul = a * b;
                int sum = mul + res[i + j + 1]; //agr pehele se present h waha koi number toh add krdo
                res[i + j + 1] = sum % 10; //i + j + 1 se humesha ones digits pe jaaega 
                res[i + j] += sum / 10; //is se carry ko left waale me daal rhe h
            }
        }
        string ans = "";
        for (int x : res) {
            if (ans.empty() && x == 0) continue; // to ignore starting zeroes

            ans += char(x + '0');
        }
        return ans;
    }
};
