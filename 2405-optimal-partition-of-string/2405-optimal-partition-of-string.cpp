class Solution {
public:
    int partitionString(string s) {
        int n = s.length();
        vector<int> dp(n+1, 0);
        int j = 0;
        unordered_set<char> seen;
        for (int i = 0; i < n; ++i) {
            while(seen.count(s[i])) {
                seen.erase(s[j++]);
            }
            seen.insert(s[i]);
            dp[i+1] = dp[j] + 1;
        }
        return dp[n];
    }
};