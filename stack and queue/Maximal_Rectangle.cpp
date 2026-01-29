/*
Problem: LeetCode 85 – Maximal Rectangle

Approach:
- Convert each row of the binary matrix into a histogram.
- For every row:
    → Maintain heights of consecutive '1's column-wise.
    → Apply Largest Rectangle in Histogram (monotonic stack).
- Update maximum area after processing each row.

Largest Rectangle in Histogram:
- Use a monotonic increasing stack storing indices.
- When a smaller bar appears, pop from stack and calculate area.
- Width is decided using nearest smaller elements.

Time Complexity: O(N * M)
Space Complexity: O(M)

Where:
N = number of rows
M = number of columns
*/

class Solution {
public:

    // LeetCode 84 helper: Largest Rectangle in Histogram
    int largestRectangleArea(vector<int> &histo) {
        stack<int> st;
        int maxA = 0;
        int n = histo.size();
        for (int i = 0; i <= n; i++) {
            // Process remaining bars when i == n
            while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
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

    // Main function: Maximal Rectangle
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> height(m, 0);
        int maxArea = 0;
        // Build histogram row by row
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }
            // Apply histogram algorithm
            int area = largestRectangleArea(height);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
