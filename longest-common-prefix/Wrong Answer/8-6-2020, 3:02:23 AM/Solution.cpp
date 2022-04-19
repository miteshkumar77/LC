// https://leetcode.com/problems/longest-common-prefix



class Solution {
    
private: 
    struct TN {
        array<TN*, 26> letters; 
        char onlychar; 
        int num_chars; 
        
        TN() {
            fill(letters.begin(), letters.end(), nullptr); 
            onlychar = ' '; 
            num_chars = 0; 
        }
    }; 
public:
    string longestCommonPrefix(vector<string>& strs) {
        TN* head = new TN(); 
        
        for (string s : strs) {
            TN* cur = head; 
            for (char c : s) {
                if (!(cur -> letters)[c - 'a']) {
                    (cur -> letters)[c - 'a'] = new TN(); 
                    ++(cur -> num_chars); 
                    (cur -> onlychar) = c; 
                }
                cur = (cur -> letters)[c - 'a']; 
            }
        }
        
           
        string ans = ""; 
        while(head -> num_chars == 1) {
            ans += (head -> onlychar); 
            head = (head -> letters)[head -> onlychar - 'a']; 
        }
        return ans; 
    }
};