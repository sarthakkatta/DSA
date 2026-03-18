/*
Problem: LeetCode 121 – Best Time to Buy and Sell Stock

Approach:
1. Track the minimum price (buy price) seen so far.
2. Traverse the array and for each price, calculate potential profit.
3. Update the maximum profit whenever a higher profit is found.
4. If a lower price is found, update the buy price.
5. Return the maximum profit.

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
            }else{
                int currprofit = prices[i] - buyprice;
                profit = max(currprofit, profit);
            }
        }
        return profit;
    }
};
