// https://leetcode.com/problems/ransom-note

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        array<int, 26> rN{0}; 
        array<int, 26> mZ{0}; 
        
        for (char c : ransomNote) {
            ++rN[c - 'a']; 
        }
        
        for (char c : magazine) {
            ++mZ[c - 'a']; 
        }
        
        for (int i = 0; i < 26; ++i) {
            if (rN[i] > mZ[i]) {
                return false; 
            }
        }
        
        return true; 
        
         
        
    }
};