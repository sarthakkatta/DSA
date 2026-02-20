/*
Problem: LeetCode 135 – Candy


Approach:
1. Traverse ratings and handle three cases:
   - Equal ratings → give 1 candy.
   - Increasing sequence → increase candy count (peak).
   - Decreasing sequence → increase count (down slope).
2. Track peak and down values to adjust overlap.
3. If down slope is longer than peak, add extra candies.
4. Sum all candies and return result.

Time Complexity: O(N)
Space Complexity: O(1)
*/


class Solution{
public:
    int candy(vector<int>& ratings){
        int n = ratings.size();
        int i = 1;
        int sum = 1;
        while(i < n){
            if(ratings[i] == ratings[i-1]){
                sum += 1;
                i++;
                continue;
            }
            int peak = 1;
            while(i < n && ratings[i] > ratings[i-1]){
                peak += 1;
                i++;
                sum += peak;
            }
            int down = 0;
            while(i < n && ratings[i] < ratings[i-1]){
                down += 1;
                i++;
                sum += down;
            }
            down++;
            if(down > peak){
                sum += down - peak;
            }
        }
        return sum;
    }
};
