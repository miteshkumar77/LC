// https://leetcode.com/problems/russian-doll-envelopes

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size(); 
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
            return a[0] < b[0]; 
        });
        
        vector<int> dp(n, 1);
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (envelopes[i][0] > envelopes[j][0] &&
                    envelopes[i][1] > envelopes[j][1]) {
                    
                    dp[i] = max(dp[i], dp[j] + 1);
                    ans = max(ans, dp[i]);
                }
            }
        }
        return ans;
    }
};