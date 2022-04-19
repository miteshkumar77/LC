// https://leetcode.com/problems/make-sum-divisible-by-p

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int fwdsum = 0;
        int n = nums.size(); 
        for (int i : nums) fwdsum += i; 
        
        int bwdsum = 0; 
        unordered_map<int,int> seen; 
        int ans = INT_MAX; 
        seen[0] = -1; 
        for (int i = 0; i < n; ++i) {
            int rf = fwdsum % p; 
            int rb = (p - rf) % p; 
            if (seen.find(rb) != seen.end()) {
                ans = min(ans, i - 1 - seen[rb]); 
            }
            bwdsum = (bwdsum + nums[i]) % p;
            fwdsum -= nums[i]; 
            seen[bwdsum] = i; 
        }
        if (ans == INT_MAX) {
            return -1; 
        }
        return ans; 
        
        
        
    }
};