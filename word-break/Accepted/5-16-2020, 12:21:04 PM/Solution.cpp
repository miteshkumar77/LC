// https://leetcode.com/problems/word-break


class Solution {
public:
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length(); 
        vector<bool> dp(n + 1, false); 
        unordered_set<string> uDict (wordDict.begin(), wordDict.end()); 
        dp[0] = true; 
        
        for (int i = 0; i <= n; ++i) {
            if (dp[i]) {
                string tmp = ""; 
                for (int j = i; j < s.length(); ++j) {
                    tmp += s[j]; 
                    if (uDict.find(tmp) != uDict.end()) {
                        dp[j + 1] = true; 
                    }
                }
            }
        }
        return dp.back(); 
    }
};
