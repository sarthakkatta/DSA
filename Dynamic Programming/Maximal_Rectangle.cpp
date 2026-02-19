/*
Problem: LeetCode 85 – Maximal Rectangle

Approach:
1. Treat each row as histogram.
2. Build height array:
      if matrix[i][j] == '1' → height[j]++
      else → height[j] = 0
3. For each row → find largest rectangle in histogram using stack.
4. Keep track of maximum area.

Time Complexity: O(N * M)
Space Complexity: O(M)
*/


class Solution {
public:

    int largestRectangleArea(
        vector<int> &histo) {
        stack<int> st;
        int maxA = 0;
        int n = histo.size();
        for (int i = 0; i <= n; i++) {
            while (!st.empty() &&(i == n ||histo[st.top()] >= histo[i])) {
                int height = histo[st.top()];
                st.pop();
                int width;
                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;

                maxA = max(maxA, width * height);
            }
            st.push(i);
        }
        return maxA;
    }

    int maximalRectangle(
        vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        if (matrix.empty() ||
            matrix[0].empty())
            return 0;

        int maxArea = 0;
        vector<int> height(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }
            int area = largestRectangleArea(height);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
