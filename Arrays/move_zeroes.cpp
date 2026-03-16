/*
Problem: LeetCode 283 – Move Zeroes

Approach:
1. Find the index of the first zero in the array.
2. Traverse the remaining array after that index.
3. Whenever a non-zero element is found, swap it with the element at index j.
4. Increment j so the next non-zero element gets placed correctly.
5. This moves all zeroes to the end while maintaining the relative order of non-zero elements.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = -1;
        for(int i = 0; i < nums.size();i++){
            if(nums[i] == 0){
                j = i;
                break;
            }
        }
        if(j == -1) return;
        for(int i = j + 1; i <nums.size(); i++){
            if(nums[i] != 0){
                swap(nums[j], nums[i]);
                j++;
            }
        }
    }
};
