//using the histogram logic


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        int n = matrix.size(), m = matrix[0].size(), maxArea = 0;
        vector<int> heights(m, 0);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }

    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int maxArea = 0, i = 0;
        stack<int> st;
        while (i < heights.size()) {
            if (st.empty() || heights[i] >= heights[st.top()]) {
                st.push(i++);
            } else {
                int h = heights[st.top()];
                st.pop();
                int w = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * w);
            }
        }
        heights.pop_back();
        return maxArea;
    }
};