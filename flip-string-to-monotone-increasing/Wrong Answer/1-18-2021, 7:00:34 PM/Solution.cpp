// https://leetcode.com/problems/flip-string-to-monotone-increasing

class Solution {
public:
    int minFlipsMonoIncr(string S) {
        if (S.length() == 0) return 0;
        S = '#' + S + '#';
        int n = S.length();

        vector<int> makeZ(n, 0);
        vector<int> makeO(n, 0);
        
        for (int i = 1; i < n - 1; ++i) {
            makeZ[i] = (S[i] != '0') + makeZ[i - 1];
        }
        for (int i = n - 2; i >= 1; --i) {
            makeO[i] = (S[i] != '1') + makeO[i + 1];
        }
        
        int ans = n - 2;
        for (int i = 1; i < n - 1; ++i) {
            ans = min(ans, makeZ[i] + makeO[i + 1]);
        }
        return ans;
        
    }
};