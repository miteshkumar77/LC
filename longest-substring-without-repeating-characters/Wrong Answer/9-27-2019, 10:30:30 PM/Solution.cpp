// https://leetcode.com/problems/longest-substring-without-repeating-characters

#include <unordered_map>
#include <iostream>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> umap;
        
        int m_len = 0;
        int len = 0; 
        if (s.size() <= 1) {
            return s.size();
        }
        
        for (int i = 0; i < s.size(); i++) {
            len++;
            if (umap[s[i]] >= (i - len + 1)) {
                
                
                len = i - umap[s[i]];
            }
            
            if (len > m_len) {
                    m_len = len;
                    
            }
            // cout << s[i] << ' '<< umap[s[i]] << ' ' << len << endl;
            umap[s[i]] = i;
        }      
        
        if (len > m_len) {
            m_len = len;
        }
        
        return m_len;
    }
};