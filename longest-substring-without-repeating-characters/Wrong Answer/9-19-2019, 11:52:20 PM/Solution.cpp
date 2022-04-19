// https://leetcode.com/problems/longest-substring-without-repeating-characters

#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> umap;
        
        int counter = 1;
        int maxLen = 0;
        int currLen = 0;
        
        
        for (int i = 0; i < s.size(); i++) {
            if (umap[s[i]] != counter) {
                
                currLen++;
            } else {
                counter++;
                if (maxLen < currLen) {
                    maxLen = currLen;
                }
                currLen = 1;
            }
            
            umap[s[i]] = counter;
        }
        
        if (maxLen < currLen) {
            maxLen = currLen;
        }
        
        return maxLen;
    }
};