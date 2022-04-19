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
    
    int minFlips(string s) {
        // bf(s);
        int a = solve(s);
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == s[i-1]) {
                reverse(s.begin(), s.begin() + i);
                s = s.substr(i, s.length() - i) + s.substr(0, i);
                a = min(a, solve(s));
                break;
            }
        }
        return a;
    }
};