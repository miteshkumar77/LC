// https://leetcode.com/problems/ransom-note

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        array<int, 26> rN{0}; 
        
        for (char c : ransomNote) {
            ++rN[c - 'a']; 
        }
        
        for (char c : magazine) {
            --rN[c - 'a']; 
        }
        
        for (int i = 0; i < 26; ++i) {
            if (rN[i] > 0) {
                return false; 
            }
        }
        
        return true;  
    }
};