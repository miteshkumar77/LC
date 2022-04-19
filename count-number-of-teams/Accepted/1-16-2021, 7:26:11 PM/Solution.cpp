// https://leetcode.com/problems/count-number-of-teams

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans = solve(rating);
        reverse(rating.begin(), rating.end()); 
        return ans + solve(rating);
    }
    
    int solve(const vector<int>& rating) {
        int n = rating.size(); 
        vector<int> dp(n, 0);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (rating[i] > rating[j]) {
                    ans += dp[j];
                    ++dp[i];
                }
            }
        }
        
        return ans;
    }
};