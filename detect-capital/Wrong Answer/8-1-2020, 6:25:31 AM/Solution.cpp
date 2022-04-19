// https://leetcode.com/problems/detect-capital

class Solution {
public:
    bool detectCapitalUse(string word) {
        bool no_uppercase = true; 
        bool all_uppercase = true; 
        bool only_first_uppercase = isupper(word[0]); 
        
        for (char c : word) {
            if (isupper(c)) {
                no_uppercase = false; 
            } else {
                all_uppercase = false; 
                only_first_uppercase = false; 
            }
            if (!(no_uppercase || all_uppercase || only_first_uppercase)) {
                return false; 
            }
        }
        return true; 
    }
};