// https://leetcode.com/problems/largest-rectangle-in-histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next_lt(n, n);
        vector<int> prev_lt(n,-1);
        
        stack<int> stk;
        
        for (int i = 0; i < n; ++i) {
            while(!stk.empty() && heights[stk.top()] > heights[i]) {
                next_lt[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        
        stk = stack<int>();
        
        for (int i = n - 1; i >= 0; --i) {
            while(!stk.empty() && heights[stk.top()] > heights[i]) {
                prev_lt[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            ans = max(ans, (next_lt[i] - prev_lt[i] - 1) * heights[i]);
        }
        return ans;
    }
};