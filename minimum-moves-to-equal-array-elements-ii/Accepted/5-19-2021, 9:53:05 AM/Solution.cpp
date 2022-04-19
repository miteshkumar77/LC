// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii

class Solution {
public:
    typedef unsigned long long int ulli;
    int minMoves2(vector<int>& nums) {
        ulli n = nums.size();
        /*
            nums[i] - nums[i-1] + nums[i] - nums[i-2] + ... + nums[i] - nums[0] = 
                i * nums[i] - (nums[0] + ... + nums[i-1])
        */
        sort(nums.begin(), nums.end());
        vector<ulli> suff(n + 1, 0);
        for (int i = (int)n - 1; i >= 0; --i) {
            suff[i] = nums[i] + suff[i+1];
        }
        ulli pref = 0;
        ulli ans = INT_MAX;
        for (ulli i = 0; i < nums.size(); ++i) {
            ans = min(ans, (ulli)i * (ulli)nums[i] - pref + suff[i+1] - (n - i - 1) * nums[i]);
            pref += nums[i];
        }
        return ans;
    }
    
};