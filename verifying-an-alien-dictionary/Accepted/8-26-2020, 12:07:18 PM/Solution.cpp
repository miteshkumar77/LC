// https://leetcode.com/problems/verifying-an-alien-dictionary

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        array<int, 26> cmp; 
        for (int i = 0; i < order.length(); ++i) {
            cmp[order[i] - 'a'] = i; 
        }
        
        for (int i = 0; i < words.size() - 1; ++i) {
            int t = 0; 
            int b = 0;
            bool valid = false; 
            while(t < words[i].length() && b < words[i + 1].length()) {
                if (cmp[words[i][t] - 'a'] < cmp[words[i + 1][b] - 'a']) {
                    valid = true; 
                    break; 
                }
                
                if (cmp[words[i][t] - 'a'] > cmp[words[i + 1][b] - 'a']) {
                    return false; 
                }
                ++t; ++b; 
            }
            
            if (t != words[i].length() && b == words[i + 1].length() && !valid) {
                return false; 
            }
        }
        return true; 
    }
};