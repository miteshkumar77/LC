// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int suff = 0;
        for (int i : nums) suff += i;
        
        int pref = 0;
        int j = -1;
        int ans = INT_MAX;
        if (suff == x) {
            ans = nums.size(); 
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            suff -= nums[i];
            
            while(j < i && pref + suff < x) {
                ++j;
                pref += nums[j];
            }
            if (pref + suff == x) {
                ans = min(ans, (int)nums.size() - i + j);
            }
        }
        return ans==INT_MAX?-1:ans;
        
    }
};