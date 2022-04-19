// https://leetcode.com/problems/detect-capital

class Solution {
public:
    bool detectCapitalUse(string word) {
        bool only_first_uppercase = isupper(word[0]); 
        bool no_uppercase = !only_first_uppercase; 
        bool all_uppercase = only_first_uppercase; 
        
        for (int i = 1; i < word.size(); ++i) {
            if (isupper(word[i])) {
                no_uppercase = false; 
            } else {
                all_uppercase = false; 
                only_first_uppercase = false; 
            }
            if (!(no_uppercase || all_uppercase || only_first_uppercase)) {
                return false; 
            }
        }
        
        return no_uppercase || all_uppercase || only_first_uppercase; 
         
    }
};