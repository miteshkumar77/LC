// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> pref_max(n+2, (int)-1e9);
        vector<int> suff_max(n+2, (int)-1e9);
        for (int i = 0; i < n; ++i) {
            pref_max[i+1] = max(pref_max[i], height[i]);
        }
        for (int i = n-1; i >= 0; --i) {
            suff_max[i+1] = max(suff_max[i+2], height[i]);
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans += min(pref_max[i], suff_max[i]) - height[i-1];
        }
        return ans;
    }
};