// https://leetcode.com/problems/number-of-matching-subsequences

class Solution {
public:
    bool isSubseq(string const& a, string const& b) {
        if (a.length() < b.length()) return false;
        int j = 0; 
        for (char c : a) {
            if (j < b.length() && c == b[j]) ++j;
            if (j == b.length()) return true;
        }
        return false;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0;
        for (string const& w : words) ans += isSubseq(s, w);
        return ans;
    }
};