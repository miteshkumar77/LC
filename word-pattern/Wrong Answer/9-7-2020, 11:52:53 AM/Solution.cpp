// https://leetcode.com/problems/word-pattern

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        str += ' ';
        string s = "";
        int ptr = 0; 
        unordered_map<char,string> mp; 
        for (char c : str) {
            if (c == ' ') {
                if (mp.find(pattern[ptr]) == mp.end()) {
                    mp[pattern[ptr]] = s; 
                }
                if (mp[pattern[ptr]] != s) {
                    return false; 
                }
                s = ""; 
                ++ptr;
            } else {
                s += c; 
            }
        }
        return true; 
    }
};