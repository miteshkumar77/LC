// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        /*
            nums[i] - nums[i-1] + nums[i] - nums[i-2] + ... + nums[i] - nums[0] = 
                i * nums[i] - (nums[0] + ... + nums[i-1])
        */
        sort(nums.begin(), nums.end());
        vector<int> suff(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            suff[i] = nums[i] + suff[i+1];
        }
        int pref = 0;
        int ans = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            ans = min(ans, i * nums[i] - pref + suff[i+1] - (n - i - 1) * nums[i]);
            pref += nums[i];
        }
        return ans;
    }
    
};