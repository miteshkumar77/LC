// https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating

class Solution {
public:
    /*
    111000
    
    1111000111   

    */
    int solve(string s) {
        int n = s.length();
        vector<array<int, 2>> dp(n + 1);
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = dp[i-1][1] + (s[i-1] != '0');
            dp[i][1] = dp[i-1][0] + (s[i-1] != '1');
        }
        return min(dp.back()[0], dp.back()[1]);
    }
    
    vector<int> slv(string s, int start) {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            dp[i+1] = dp[i] + ((start + '0') == s[i]);
            start = (start+1) % 2;
        }
        return dp;
    }
    
    void bf(string s) {
        cout << s << ' ' << solve(s) << endl;
        for (int i = 0; i < s.length(); ++i) {
            s = s.substr(1, s.length() - 1) + s.substr(0,1);
            cout << s << ' ' << solve(s) << endl;
        }
    }
    
    int minFlips(string s) {
        int n = s.length();
        auto pref0 = slv(s, 0);
        auto pref1 = slv(s, 1);
        reverse(s.begin(), s.end());
        auto suff0 = slv(s, 0);
        auto suff1 = slv(s, 1);
        reverse(suff0.begin(), suff0.end());
        reverse(suff1.begin(), suff1.end());
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, min(pref0[i] + suff1[i], pref1[i] + suff0[i]));
        }
        return ans;
        
    }
};