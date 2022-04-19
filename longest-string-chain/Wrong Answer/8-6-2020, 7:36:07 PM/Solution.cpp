// https://leetcode.com/problems/longest-string-chain

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(), words.end(), [](const string& a, const string& b) -> bool {
            return a.length() > b.length();  
        });
        sort(words.begin(), words.end()); 
        unordered_map<string, int> dp; 
        int ans = 0; 
        for (string w : words) {
            int mlen = 0; 
            for (int i = 0; i < w.length(); ++i) {
                string s = w.substr(0, i) + w.substr(i + 1); 
                mlen = max(mlen, dp[s] + 1); 
            }
            dp[w] = mlen; 
            ans = max(mlen, ans); 
        }
        return ans; 
    }
    
    
};