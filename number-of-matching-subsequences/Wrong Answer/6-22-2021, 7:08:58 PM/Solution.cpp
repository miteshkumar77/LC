// https://leetcode.com/problems/number-of-matching-subsequences

class Solution {
public:
    struct TN {
        TN() : letters(26, nullptr) {}
        int words{0};
        vector<TN*> letters;
        unordered_map<int,int> dp;
    };
    
    void insert(TN* root, string const& word) {
        for (char c : word) {
            if (!(root->letters)[c-'a']) {
                (root->letters)[c-'a'] = new TN();
            }
            root = (root->letters)[c-'a'];
        }
        ++(root->words);
    }
    
    int bt(string const& s, TN* head, int idx) {
        if (!head) return 0;
        if (idx == s.length()) return 0;
        if ((head->dp).count(idx)) return (head->dp)[idx];
        (head->dp)[idx] = head->words + bt(s, head, idx+1) + bt(s, (head->letters)[s[idx]-'a'], idx+1);
        return (head->dp)[idx];
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        /*TN* head = new TN();
        for (string const& w : words) insert(head, w);
        return bt(s, head, 0);*/
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int>(26, INT_MAX));
        for (int i = n-1; i >= 0; --i) {
            for (int j = 0; j < 26; ++j) {
                if (s[i]-'a' == j) {
                    dp[i][j] = i;
                } else {
                    dp[i][j] = dp[i+1][j];
                }
            }
        }
        int ans = 0;   
        int si;
        for (string const& w : words) {
            si = 0;
            bool ok = true;
            for (char c : w) {
                if (dp[si][c-'a'] == INT_MAX) {
                    ok = false;
                    break;
                }
                si = dp[si][c-'a'];
            }
            ans += ok;
        }
        return ans;
    }
};