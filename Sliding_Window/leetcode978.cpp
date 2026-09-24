/*
Problem:
---------
LeetCode 978 - Longest Turbulent Subarray

Approach:
---------
1. A turbulent subarray is one where the comparison between consecutive
   elements alternates:

       > < > < ...
   
   or:

       < > < > ...

2. Maintain two variables:
   - `up`   -> length of the current turbulent subarray ending at the
               current index where the last comparison is increasing.
   - `down` -> length of the current turbulent subarray ending at the
               current index where the last comparison is decreasing.

3. If:

       arr[i] > arr[i - 1]

   then the current comparison is increasing.

   To maintain turbulence, the previous comparison must have been
   decreasing, so:

       up = down + 1

   `down` is reset to 1 because the current ending comparison is not
   decreasing.

4. If:

       arr[i] < arr[i - 1]

   then the current comparison is decreasing.

   The previous comparison must have been increasing, so:

       down = up + 1

   `up` is reset to 1.

5. If:

       arr[i] == arr[i - 1]

   the turbulent pattern breaks completely.

   Therefore:

       up = 1
       down = 1

6. At every index, update the maximum length:

       ans = max(ans, max(up, down))

7. Return `ans`.

Key Idea:
---------
The main idea is to track the two possible states of a turbulent
subarray:

    up   -> last movement was increasing
    down -> last movement was decreasing

If the current value increases:

    up = down + 1

because an increasing comparison can only continue a turbulent sequence
if the previous comparison was decreasing.

Similarly, if the current value decreases:

    down = up + 1

If two consecutive values are equal, turbulence breaks and both values
are reset to 1.

This allows us to solve the problem in one pass without storing the
entire DP array.

Example:
--------
arr = [9, 4, 2, 10, 7, 8, 8, 1, 9]

Comparisons:

    9 > 4
    4 > 2
    2 < 10
    10 > 7
    7 < 8

The longest alternating sequence is:

    [4, 2, 10, 7, 8]

Its comparisons are:

    > < > <

So its length is 5.

When we encounter:

    8 == 8

the turbulent sequence breaks, so both `up` and `down` are reset.

Time Complexity:
----------------
O(n)

We traverse the array exactly once.

Space Complexity:
-----------------
O(1)

Only `up`, `down`, `ans`, and a few variables are used.
*/

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 1;
        int up = 1;
        int down = 1;
        int ans = 1;
        for(int i = 1; i < n; i++){
            if(arr[i] > arr[i - 1]){
                up = down + 1;
                down = 1;
            }else if(arr[i] < arr[i - 1]){
                down = up + 1;
                up = 1;
            }else{
                up = 1;
                down = 1;
            }
            ans = max(ans, max(up, down));
        }
        return ans;
    }
};
