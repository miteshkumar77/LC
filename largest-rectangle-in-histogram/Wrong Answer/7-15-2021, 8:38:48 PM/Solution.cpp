// https://leetcode.com/problems/largest-rectangle-in-histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int ans = 0;
        int n = heights.size();
        vector<int> add(n+1, 0);
        for (int i = 0; i <= n; ++i) {
            while(!stk.empty() && (i == n || heights[i] < heights[stk.top()])) {
                ans = max(ans, (i - stk.top() + add[stk.top()]) * heights[stk.top()]);
                ++add[i];
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};