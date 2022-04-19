// https://leetcode.com/problems/palindrome-partitioning

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans; 
        vector<string> phrase; 
        backtrack(ans, phrase, s, 0); 
        return ans; 
        
        
    }
    
    
    void backtrack(vector<vector<string>>& ans, vector<string>& phrase, const string& s, int i) {
        if (i == s.length()) {
            ans.push_back(phrase); 
            return; 
        }
        
        string box = ""; 
        for (int x = i; x <= s.length(); ++x) {
            box += s[x]; 
            if (checkPal(box)) {
                phrase.push_back(box); 
                backtrack(ans, phrase, s, x + 1); 
                phrase.pop_back(); 
            }
        }
    }
    
    bool checkPal(string& s) {
        int L = 0;
        int R = s.length() - 1; 
        while(L < R) {
            if (s[L++] != s[R--]) {
                return false; 
            }
        }
        return true; 
    }
};