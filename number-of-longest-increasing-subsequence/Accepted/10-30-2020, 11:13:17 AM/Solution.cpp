// https://leetcode.com/problems/number-of-longest-increasing-subsequence

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        vector<int> ct(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    int nxt = dp[j] + 1;
                    if (nxt > dp[i]) {
                        dp[i] = nxt;
                        ct[i] = ct[j];
                    } else if (nxt == dp[i]) {
                        ct[i] += ct[j];
                    }
                }    
            }
        }
        // for (int i : dp) cout << i << ' ';
        // cout << endl;
        // for (int i : ct) cout << i << ' ';
        // cout << endl;
        
        int ans = 0;
        int len = 0;
        for (int i = 0; i < dp.size(); ++i) {
            if (dp[i] > len) {
                ans = ct[i];
                len = dp[i];
            } else if (dp[i] == len) {
                ans += ct[i];
            }
        }
        return ans;
    }
};