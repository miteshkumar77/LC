// https://leetcode.com/problems/largest-rectangle-in-histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int ans = 0;
        int n = heights.size();
        for (int i = 0; i <= n; ++i) {
            while(!stk.empty() && (i == n || heights[i] < heights[stk.top()])) {
                ans = max(ans, (i - stk.top()) * heights[stk.top()]);
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};