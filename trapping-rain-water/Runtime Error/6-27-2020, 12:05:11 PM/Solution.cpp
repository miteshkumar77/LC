// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size() - 1; 
        vector<int> pref(height.size(), 0); 
        vector<int> suff(height.size(), 0); 
        
        pref[0] = height[0]; 
        suff[n] = height[n]; 
        
        for (int i = 1; i <= n; ++i) {
            pref[i] = max(pref[i - 1], height[i]); 
            suff[n - i] = max(suff[n - i + 1], height[n - i]); 
        }
        int ans = 0; 
        for (int i = 1; i < height.size() - 1; ++i) {
            ans += min(pref[i], suff[i]) - height[i]; 
        }
        return ans; 
    }
};