// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters

class Solution {
public:
    
    bool intersec(unordered_set<char> u1, unordered_set<char> u2) {
        for (char c : u1) {
            if (u2.find(c) != u2.end()) {
                return false;
            }
        }
        
        return true; 
    }
    
    unordered_set<char> onion(unordered_set<char> u1, unordered_set<char> u2) {
        unordered_set<char> ans;
        for (char c : u1) ans.insert(c);
        for (char c : u2) ans.insert(c);
        return ans;
    }
    
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        vector<unordered_set<char>> dp(arr.size());
        
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            unordered_set<char> d(arr[i].begin(), arr[i].end());
            if (d.size() == arr[i].length()) {
                dp[i] = d;
            }
            if (dp[i].size() != 0) {
                for (int j = 0; j < i; ++j) {
                    if (dp[j].size() != 0 && intersec(d, dp[j])) {
                        auto st = onion(d, dp[j]);
                        if (st.size() > dp[i].size()) {
                            dp[i] = st;
                        }
                    }
                }
                ans = max(ans, (int)dp[i].size());
            }
        }
        return ans;
        
    }
};