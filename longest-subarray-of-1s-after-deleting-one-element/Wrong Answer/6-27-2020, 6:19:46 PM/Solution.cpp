// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n = nums.size() - 1; 
        
        if (n == 0) {
            return 0; 
        }
        vector<int> pref(nums.size(), 0); 
        vector<int> suff(nums.size(), 0); 
        pref[0] = nums[0]; suff[n] = nums[n]; 
        
        for (int i = 1; i <= n; ++i) {
            if (nums[i] == 0) {
                pref[i] = 0; 
            } else {
                 
                pref[i] = pref[i - 1] + 1; 
                
            }
            
            if (nums[n - i] == 0) {
                suff[n - i] = 0; 
            } else {
                suff[n - i] = suff[n - i + 1] + 1; 
            }
        }
        
        
        int ans = max(pref[n - 1], suff[0]); 
        
        
        for (int i = 1; i < n; ++i) {
            ans = max(ans, pref[i - 1] + suff[i + 1]); 
        }
        return ans; 
    }
};