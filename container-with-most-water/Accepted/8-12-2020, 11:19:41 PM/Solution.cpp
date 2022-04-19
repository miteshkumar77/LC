// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
        int L = 0; 
        int R = height.size() - 1; 
        
        int ans = 0; 
        
        while(L < R) {
            ans = max(ans, min(height[L], height[R]) * (R - L));
            if (height[L] < height[R]) {
                ++L; 
            } else {
                --R; 
            }
        }
        
        return ans; 
    }
};