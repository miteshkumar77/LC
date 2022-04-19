// https://leetcode.com/problems/make-the-string-great

class Solution {
public:
    string makeGood(string s) {
        while(true) {
            for (int i = 0; i < (signed int)s.length() - 1; ++i) {
                if ('a' <= s[i] && 'z' >= s[i] && s[i + 1] == toupper(s[i]) || 
                   'a' <= s[i + 1] && 'z' >= s[i + 1] && s[i] == toupper(s[i + 1])) {
                    s[i] = '_';
                    s[i + 1] = '_'; 
                    ++i; 
                }
            }
            
            string news = ""; 
            for (char c : s) {
                if (c != '_') {
                    news += c; 
                }
            }
            
            if (news.length() == s.length()) {
                return news; 
            }
            news.swap(s); 
        }
        return s; 
    }
};