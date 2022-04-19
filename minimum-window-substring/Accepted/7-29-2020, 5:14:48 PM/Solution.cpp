// https://leetcode.com/problems/minimum-window-substring

class Solution {
public:
    string minWindow(string s, string t) {
         
        int ref_size = t.length(); 
        int window_size = 0; 
        unordered_map<char, int> ref;
        unordered_map<char, int> window; 
        for (char c : t) {
            ++ref[c]; 
        }
        
        int j = 0; 
        bool exists = false; 
        int min_len = INT_MAX; 
        int min_j;
        
        for (int i = 0; i < s.length(); ++i) {
            ++window[s[i]];
            if (window[s[i]] <= ref[s[i]]) {
                ++window_size;
            }
            
            while(j <= i && window_size >= ref_size) {
                
                exists = true; 
                if (i - j + 1 < min_len) {
                    min_len = i - j + 1;
                    min_j = j; 
                }
                if (window[s[j]] <= ref[s[j]]) {
                    --window_size;
                }
                --window[s[j]];
                ++j; 

            }
        }
        
        
        if (exists) {
            return s.substr(min_j, min_len);
        } else {
            return ""; 
        }
        
        
        

        
        
    }
};