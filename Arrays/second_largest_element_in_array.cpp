/*
Problem: Find Second Largest Element in an Array

Approach:
1. Maintain two variables: largest and secondLargest.
2. Traverse the array once.
3. If the current element is greater than largest, update secondLargest and largest.
4. Otherwise if it is smaller than largest but greater than secondLargest, update secondLargest.
5. Return the secondLargest element.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int getSecondLargest(vector<int> &arr) {
        int sl = -1;
        int lar = arr[0];
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] > lar){
                sl = lar;
                lar = arr[i];
            }else if(arr[i] < lar && arr[i] > sl){
                sl = arr[i];
            }
        }
        return sl;
    }
};
