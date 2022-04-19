// https://leetcode.com/problems/ransom-note

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int i = 0; 
        int j = 0; 
        
        if (ransomNote.length() == 0) {
            return true; 
        }
        
        for (; j < magazine.length(); ++j) {
            if (i == ransomNote.length()) {
                return true;
            }
            
            if (ransomNote[i] == magazine[j]) {
                ++i; 
            }
        }
        
        return false; 
    }
};