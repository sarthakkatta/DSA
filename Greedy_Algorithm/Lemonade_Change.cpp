/*
Problem: LeetCode 860 – Lemonade Change

Approach:
1. Keep count of $5 and $10 bills.
2. If customer pays with $5, increase five count.
3. If customer pays with $10, give one $5 as change.
4. If customer pays with $20:
   - Prefer giving one $10 and one $5.
   - Otherwise give three $5 bills.
5. If change cannot be given at any point, return false.

Time Complexity: O(N)
Space Complexity: O(1)
*/


class Solution {
public:

    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for(int i = 0; i < bills.size(); i++){
            if(bills[i] == 5){
                five += 1;
            }
            else if(bills[i] == 10){
                if(five == 0) return false;
                ten += 1;
                five -= 1;
            }
            else
                if(ten > 0 && five > 0){
                    ten -= 1;
                    five -= 1;
                }
                else if(five >= 3){
                    five -= 3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};
