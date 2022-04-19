// https://leetcode.com/problems/concatenated-words

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans; 
        unordered_set<string> dict(words.begin(), words.end());
        for (string s : words) {
            if (check(s, dict)) {
                ans.push_back(s);
            }
        }
        return ans; 
    }
    
    
    bool check(string& s, unordered_set<string>& dict) {
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        int num = 0;
        for (int i = 0; i <= s.length(); ++i) {
            if (dp[i]) {
                string t = "";
                for (int j = i; j < s.length(); ++j) {
                    t += s[j]; 
                    if (dict.find(t) != dict.end()) {
                        dp[j + 1] = true;
                        if (j == s.length() - 1 && i != 0) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};