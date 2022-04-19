// https://leetcode.com/problems/check-if-a-string-can-break-another-string

class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        
        
        return check(s1, s2) || check(s2, s1);  
    }
    
    
    bool check(string s1, string s2) {
        unordered_map<char, int> occs; 
        for (char c : s1) {
            ++occs[c];
        }
        
        
        for (int i = 0; i < s2.size(); ++i) {
            char closest = s2[i] + 1; 
            for (pair<char, int> p : occs) {
                char c = p.first; 
                if (c <= s2[i] && (closest > s2[i] || (s2[i] - closest) > (s2[i] - c))) {
                    closest = c; 
                }
            }
            
            if (closest > s2[i]) {
                return false; 
            }
            
            if (occs[closest] == 1) {
                occs.erase(closest); 
            } else {
                --occs[closest]; 
            }
        }
        
        return true; 
    }
};