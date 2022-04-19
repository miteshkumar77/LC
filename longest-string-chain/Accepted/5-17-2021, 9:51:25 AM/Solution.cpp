// https://leetcode.com/problems/longest-string-chain

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) -> bool {
            return a.length() < b.length();
        });
        int ans = 0;
        unordered_map<string, int> dp;
        for (const string& s : words) {
            dp[s] = 1;
            for (int i = 0; i < s.length(); ++i) {
                string tmp = s.substr(0, i) + s.substr(i + 1, s.length() - i - 1);
                if (dp.count(tmp)) {
                    dp[s] = max(dp[s], dp[tmp] + 1);
                }
            }
            ans = max(ans, dp[s]);
        }
        return ans;
    }
};