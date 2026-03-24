/*
Problem: LeetCode 118 – Pascal’s Triangle

Approach:
1. Each row of Pascal’s Triangle can be generated using the previous value.
2. Start every row with 1.
3. Use the formula: nCr = nCr-1 * (n - r) / r to compute next elements.
4. Generate each row independently and store in the result.
5. Repeat for all rows from 1 to numRows.

Time Complexity: O(N^2)
Space Complexity: O(N^2)
*/

class Solution {
public:
    vector<int> generateRows(int row){
        vector<int> ansRow;
        long long ans = 1;
        ansRow.push_back(1);
        for(int col = 1; col < row; col++){
            ans = ans * (row - col);
            ans = ans / col;
            ansRow.push_back(ans);
        }
        return ansRow;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int row = 1; row <= numRows; row++){
            result.push_back(generateRows(row));
        }
        return result;
    }
};
