/*
Problem: LeetCode 134 – Gas Station


Approach:
1. Calculate total gas and total cost.
2. If total gas < total cost, completing circuit is impossible.
3. Traverse stations and maintain current gas balance.
4. If current gas becomes negative, reset start to next station.
5. Return valid start index if total gas >= total cost.

Time Complexity: O(N)
Space Complexity: O(1)
*/


class Solution{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
        int totalgas = 0, totalcost = 0;
        int start = 0, currgas = 0;
        int n = gas.size();
        for(int i = 0; i < n; i++){
            totalgas += gas[i];
            totalcost += cost[i];
            currgas += (gas[i] - cost[i]);
            if(currgas < 0){
                start = i + 1;
                currgas = 0;
            }
        }
        if(totalgas < totalcost){
            return -1;
        }
        return start;
    }
};
