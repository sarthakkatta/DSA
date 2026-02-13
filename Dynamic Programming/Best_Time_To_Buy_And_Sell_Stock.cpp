/*
Problem: LeetCode 121 – Best Time to Buy and Sell Stock

Approach:
1. Keep track of minimum buying price so far.
2. For each day:
      calculate current profit.
3. Update maximum profit if current is greater.
4. Return maximum profit at end.

Time Complexity: O(N)
Space Complexity: O(1)
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int buyprice = prices[0];
        int profit = 0;

        for(int i = 0; i < prices.size(); i++){

            if(prices[i] < buyprice){
                buyprice = prices[i];
            }
            else{
                int currprofit = prices[i] - buyprice;
                profit = max(currprofit, profit);
            }
        }

        return profit;
    }
};
