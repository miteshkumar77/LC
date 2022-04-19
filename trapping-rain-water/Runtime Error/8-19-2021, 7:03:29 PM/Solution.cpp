// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        int ans = 0;
        int m = min(height[l], height[r]);
        while(l <= r) {
            if (height[l] <= height[r]) {
                ans += max(0, m - height[l++]);
                m = max(m, min(height[l], height[r]));
            } else {
                ans += max(0, m - height[r--]);
                m = max(m, min(height[l], height[r]));
            }
        }
        return ans;
    }
};