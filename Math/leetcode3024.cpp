/*
Problem:
---------
LeetCode 3024 - Type of Triangle


Approach:
---------
We first check whether the three given side lengths can actually form a
valid triangle.

For a valid triangle, the sum of any two sides must be greater than the
third side:

    a + b > c
    b + c > a
    c + a > b

This check is handled separately using the `isvalidtriangle()` function.

If the sides do not form a valid triangle, we immediately return `"none"`.

If the triangle is valid, we determine its type by comparing the three
side lengths:

1. Equilateral:
   All three sides are equal.

2. Isosceles:
   Any two sides are equal.

3. Scalene:
   All three sides are different.

The conditions are checked in this order so that an equilateral triangle
is not incorrectly classified as isosceles.


Key Idea:
---------
The main idea is to separate the problem into two steps:

Step 1: Check triangle validity.

    a + b > c
    b + c > a
    c + a > b

If any of these conditions fails, the three sides cannot form a triangle.

Step 2: Classify the valid triangle based on side equality.

    a == b == c       -> equilateral
    any two equal     -> isosceles
    all different     -> scalene

The helper function `isvalidtriangle()` makes the validity check
independent from the classification logic.


Example:
--------
Input:
nums = [3, 3, 3]

Triangle validity:
    3 + 3 > 3
    3 + 3 > 3
    3 + 3 > 3

So the triangle is valid.

Since:
    3 == 3 == 3

The answer is:

    "equilateral"


Another Example:
----------------
Input:
nums = [3, 4, 5]

Triangle validity:
    3 + 4 > 5  -> true
    4 + 5 > 3  -> true
    5 + 3 > 4  -> true

All three sides are different, so the answer is:

    "scalene"


Time Complexity:
----------------
O(1)

There are only three sides, so the number of comparisons and operations
is constant.


Space Complexity:
-----------------
O(1)

Only a few integer variables are used, so the extra space is constant.
*/

class Solution {
public:
    bool isvalidtriangle(vector<int>& arr){
        int a = arr[0], b = arr[1], c = arr[2];
        if(a+b>c && b+c>a && c+a>b)return true;
        return false;
    }
    string triangleType(vector<int>& nums) {
        if(!isvalidtriangle(nums))return "none";
        if(nums[0]==nums[1] && nums[1]==nums[2])return "equilateral";
        else if(nums[0]==nums[1] || nums[1]==nums[2] || nums[0]==nums[2])return "isosceles";
        else if(nums[0]!=nums[1] && nums[1]!=nums[2] && nums[0]!=nums[2])return "scalene";
        return "none";
    }
};
