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
    
    void bf(string s) {
        cout << s << ' ' << solve(s) << endl;
        for (int i = 0; i < s.length(); ++i) {
            s = s.substr(1, s.length() - 1) + s.substr(0,1);
            cout << s << ' ' << solve(s) << endl;
        }
    }
    
    int minFlips0(string s) {
        int n = s.length();
        vector<array<int, 2>> fw(n + 1, {0, 0});
        vector<array<int, 2>> bw(n + 1, {0, (int)1e9});
        for (int i = 1; i <= n; ++i) {
            fw[i][0] = fw[i-1][1] + (s[i-1] != '0');
            fw[i][1] = fw[i-1][0] + (s[i-1] != '1');
        }
        for (int i = n-1; i >= 0; --i) {
            bw[i][0] = bw[i+1][1] + (s[i] != '0');
            bw[i][1] = bw[i+1][0] + (s[i] != '1');
        }
        int ans = INT_MAX;
        for (int i = 0; i <= n; ++i) {
            ans = min(ans, fw[i][1] + min(bw[i][0], bw[i][1]));
        }
        return ans;
    }
    int minFlips1(string s) {
        int n = s.length();
        vector<array<int, 2>> fw(n + 1, {0, 0});
        vector<array<int, 2>> bw(n + 1, {(int)1e9, 0});
        for (int i = 1; i <= n; ++i) {
            fw[i][0] = fw[i-1][1] + (s[i-1] != '0');
            fw[i][1] = fw[i-1][0] + (s[i-1] != '1');
        }
        for (int i = n-1; i >= 0; --i) {
            bw[i][0] = bw[i+1][1] + (s[i] != '0');
            bw[i][1] = bw[i+1][0] + (s[i] != '1');
        }
        int ans = INT_MAX;
        for (int i = 0; i <= n; ++i) {
            ans = min(ans, fw[i][0] + min(bw[i][0], bw[i][1]));
        }
        return ans;
    }
    
    int minFlips(string s) {
        return min(minFlips0(s), minFlips1(s));
    }
};