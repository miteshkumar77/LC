// https://leetcode.com/problems/minimum-number-of-frogs-croaking

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        array<char, 26> cmap; 
        cmap['r' - 'a'] = 'c'; 
        cmap['o' - 'a'] = 'r'; 
        cmap['a' - 'a'] = 'o'; 
        cmap['k' - 'a'] = 'a'; 
        array<int, 26> occs{0}; 
        
        
        int max_frog = 0; 
        
        for (char c: croakOfFrogs) {
            if (c == 'c') {
                ++max_frog; 
            }
            if (c != 'k') {
                occs[c - 'a']++; 
            }
            if (c != 'c') {
                occs[cmap[c - 'a'] - 'a']--; 
                if (occs[cmap[c - 'a'] - 'a'] < 0) {
                    return -1; 
                }
            }
        }
        
        for (int i = 0; i < 26; ++i) {
            if (occs[i] != 0) {
                return -1; 
            }
        }
        return max_frog; 
        
    }
};