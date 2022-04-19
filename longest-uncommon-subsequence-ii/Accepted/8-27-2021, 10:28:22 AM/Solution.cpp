// https://leetcode.com/problems/longest-uncommon-subsequence-ii

class Solution {
public:
    bool is_subseq(string const& b, string const& s) {
        int j = 0;
        for (char c : b) {
            if (c == s[j]) {
                if (++j == s.length()) {
                    return true;
                }
            }
        }
        return false;
    }
    
    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            bool ok = true;
            for (int j = 0; j < n; ++j) {
                if (j == i) continue;
                if (is_subseq(strs[j], strs[i])) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans = max(ans, (int)strs[i].length());
            }
        }
        return ans;
    }
};