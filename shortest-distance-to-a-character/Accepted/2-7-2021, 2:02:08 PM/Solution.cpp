// https://leetcode.com/problems/shortest-distance-to-a-character

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length(); 
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            if (s[i] == c) ans[i] = 0;
            else if (i == 0) ans[i] = 1e9 + 7; 
            else ans[i] = ans[i - 1] + 1;
        }
        for (int i = n - 2; i >= 0; --i) {
            ans[i] = min(ans[i], ans[i + 1] + 1);
        }
        return ans;
    }
};