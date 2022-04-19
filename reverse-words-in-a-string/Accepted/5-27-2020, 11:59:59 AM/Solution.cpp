// https://leetcode.com/problems/reverse-words-in-a-string

class Solution {
public:
    string reverseWords(string s) {
        string ret = ""; 
        string word; 
        s += ' '; 
        vector<string> words; 
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                if (word.length() != 0) {
                    words.push_back(word); 
                    word = ""; 
                }
            } else {
                word += s[i]; 
            }
        }
        
        
        for (int i = words.size() - 1; i > 0; --i) {
            ret += words[i] + ' '; 
        }
        if (words.size() != 0) {
            ret += words[0]; 
        }
        return ret; 
        
        
    }
};