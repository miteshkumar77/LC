// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> idx; 
        int last_repeated_char_idx = -1; 
        int max_len = 0; 
        
        for (int i = 0; i < s.length(); ++i) {
            unordered_map<char, int>::iterator it = idx.find(s[i]); 
            if (it == idx.end()) {
                if (i - last_repeated_char_idx + 1 > max_len) {
                    max_len = i - last_repeated_char_idx; 
                }
                idx[s[i]] = i; 
            } else {
                if (it -> second > last_repeated_char_idx) {
                    last_repeated_char_idx = it -> second; 
                }
                if (i - last_repeated_char_idx + 1 > max_len) {
                    max_len = i - last_repeated_char_idx; 
                }
                idx[s[i]] = i; 
                
            }
        }
        
        return max_len; 
        
    }
};