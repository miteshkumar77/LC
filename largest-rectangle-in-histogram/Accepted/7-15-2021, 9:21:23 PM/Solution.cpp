// https://leetcode.com/problems/largest-rectangle-in-histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> stk;
        int ans = *max_element(heights.begin(), heights.end());
        int n = heights.size();
        vector<int> h(n, 0);
        for (int i = 0; i < n; ++i) {
            h[i] = 1;
            while(!stk.empty() && heights[i] < heights[stk.top()]) {
                ans = max(ans, heights[stk.top()] * (i + h[stk.top()] - 1 - stk.top()));
                h[i] += h[stk.top()];
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};