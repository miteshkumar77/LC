// https://leetcode.com/problems/word-break

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length() + 1, false); 
        unordered_set<string> wD(wordDict.begin(), wordDict.end()); 
        dp[0] = true; 
        
        for (int i = 0; i < dp.size(); ++i) {
            if (dp[i]) {
                string w = ""; 
                for (int j = i + 1; j < dp.size(); ++j) {
                    w += s[j - 1]; 
                    if (wD.find(w) != wD.end()) {
                        dp[j] = true; 
                    }
                }
            }
        }
        
        return dp.back(); 
    }
};