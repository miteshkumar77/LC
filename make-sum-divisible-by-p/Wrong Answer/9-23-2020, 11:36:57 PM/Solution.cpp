// https://leetcode.com/problems/make-sum-divisible-by-p

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size(); 
        
        int fwdsum = 0;
        for (int i : nums) fwdsum = (fwdsum + i) % p; 
        
        int bwdsum = 0; 
        unordered_map<int,int> seen; 
        seen[0] = -1; 
        int ans = INT_MAX; 
        for (int i = 0; i < n; ++i) {
            int r = (p - fwdsum) % p; 
            if (seen.find(r) != seen.end()) {
                ans = min(ans, i - seen[r] - 1); 
            }
            fwdsum = (fwdsum % p + p - nums[i] % p) % p; 
            bwdsum = (bwdsum + nums[i]) % p; 
            seen[bwdsum] = i; 
        }
        int r = (p - fwdsum) % p; 
        ans = min(ans, n - seen[r] - 1);
        
        return ans == INT_MAX?-1:ans; 
        
    }
};