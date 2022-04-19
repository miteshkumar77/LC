// https://leetcode.com/problems/ransom-note

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int i = 0; 
        int j = 0; 
        
        
        for (; j < magazine.length(); ++j) {
            if (i == ransomNote.length()) {
                return true;
            }
            
            if (ransomNote[i] == magazine[j]) {
                ++i; 
            }
        }
        
        if (i == ransomNote.length()) {
            return true; 
        }
        return false; 
    }
};