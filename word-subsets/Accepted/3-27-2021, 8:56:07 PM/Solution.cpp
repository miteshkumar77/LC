// https://leetcode.com/problems/word-subsets

class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> ct(26, 0);
        vector<int> ctb(26, 0);
        vector<string> ans;
        for (const string& s : B) {
            for (char c : s) {
                ++ct[c - 'a'];
            }
            
            for (int i = 0; i < 26; ++i) {
                ctb[i] = max(ctb[i], ct[i]);
                ct[i] = 0;
            }
        }
        
        for (const string& a : A) {
            for (char c : a) {
                ++ct[c - 'a'];
            }
            bool ok = true;
            for (int i = 0; i < 26; ++i) {
                if (ct[i] < ctb[i]) {
                    ok = false;
                    break;
                } 
            }
            for (int i = 0; i < 26; ++i) {
                ct[i] = 0;
            }
            if (ok) {
                ans.push_back(a);
            }
        }
        return ans;
        
    }
};