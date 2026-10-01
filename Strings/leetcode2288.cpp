/*
Problem:
---------
LeetCode 2288 - Apply Discount to Prices


Approach:
---------
We use `stringstream` to split the sentence into individual words.

For every word, we first check whether it represents a valid price.

A word is considered a valid price only when:
- It contains at least 2 characters.
- Its first character is `$`.
- Every character after `$` is a digit.

If the word is a valid price:
- Remove the `$` using `substr(1)`.
- Convert the remaining number from string to `long long` using `stoll()`.
- Apply the given discount.
- Use another `stringstream` with `fixed` and `setprecision(2)` to
  format the discounted price with exactly two decimal places.
- Add `$` back to the formatted price.

If the word is not a valid price, we keep it unchanged.

Finally, all processed words are joined back together with spaces.


Key Idea:
---------
The important part is correctly identifying valid prices.

For example:
    "$100"      -> valid
    "$5"        -> valid
    "$abc"      -> invalid
    "100$"      -> invalid
    "$12a"      -> invalid
    "$"         -> invalid

The condition:

    word.size() <= 1 || word[0] != '$'

first checks whether the word has the required `$` followed by at
least one character.

Then we check every character after `$` using `isdigit()`.

Once a valid price is found, the discounted value is calculated as:

    price * (100 - discount) / 100.0

Using `100.0` ensures floating-point division, allowing us to preserve
the decimal part.

Finally:

    fixed << setprecision(2)

ensures every discounted price contains exactly two digits after the
decimal point.


Example:
--------
Input:
sentence = "there are $100 and $50"
discount = 20

Processing:
    "$100" -> 100 × 80 / 100 = 80.00
    "$50"  -> 50 × 80 / 100 = 40.00

Output:
    "there are $80.00 and $40.00"

Invalid price-like words are simply left unchanged.


Time Complexity:
----------------
O(n)

We process every character of the sentence while splitting and checking
the words, where `n` is the length of the sentence.


Space Complexity:
-----------------
O(n)

The words and final answer together can require O(n) additional space.
*/

class Solution {
public:
    string discountPrices(string sentence, int discount) {
        stringstream ss(sentence);
        string word;
        string ans = "";
        while (ss >> word) {
            // Check if word is a valid price
            bool valid = true;
            if (word.size() <= 1 || word[0] != '$') {
                valid = false;
            }
            for (int i = 1; i < word.size(); i++) {
                if (!isdigit(word[i])) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                long long price = stoll(word.substr(1));
                double newPrice = price * (100 - discount) / 100.0;
                stringstream temp;
                temp << fixed << setprecision(2) << newPrice;

                word = "$" + temp.str();
            }
            if (ans != "") ans += " ";

            ans += word;
        }
        return ans;
    }
};
