// https://leetcode.com/problems/letter-case-permutation

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        for (int i = 0; i < S.length(); ++i) {
            if (!isdigit(S[i])) {
                S[i] = tolower(S[i]); 
            }
        }
        vector<string> ans; 
        bt(S, ans, 0, true); 
        return ans; 
    }
    
    void bt(string& s, vector<string>& ans, int i, bool good) {
        if (i == s.length()) {
            ans.push_back(s); 
            return; 
        }
        if (isdigit(s[i])) {
            bt(s, ans, i + 1, good); 
            return; 
        }
        
        if (good) {
            bt(s, ans, i + 1, true); 
        }
        
        s[i] = toupper(s[i]); 
        bt(s, ans, i + 1, true); 
        s[i] = tolower(s[i]); 
    }
    
    
    
};