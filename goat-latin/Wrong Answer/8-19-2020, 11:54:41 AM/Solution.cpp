// https://leetcode.com/problems/goat-latin

class Solution {
public:
    string toGoatLatin(string S) {
        string ans = ""; 
        string word = ""; 
        int idx = 0; 
        for (char c : S) {
            if (c == ' ') {
                // cout << word << endl; 
                if (word.length() == 0) {
                    continue; 
                }
                ans += conv(word, idx++) + ' '; 
                word = ""; 
            } else {
                word += c; 
            }
        }
        // cout << word << endl; 
        if (word.length() != 0) {
            ans += conv(word, idx++);
        }
        return ans; 
    }
    
    string conv(string& w, int idx) {
        string s; 
        if (w[0] == 'a' || w[0] == 'e' || w[0] == 'i' || w[0] == 'u' || 
           w[0] == 'A' || w[0] == 'I' || w[0] == 'E' || w[0] == 'U') {
            
            s = w + "ma"; 
            // cout << s << endl; 
        } else {
            s = w.substr(1) + w[0] + "ma"; 
            // cout <<"s: " << s << endl; 
        }
        // cout << s << endl; 
        // cout << endl; 
        
        s += string(idx + 1, 'a'); 
        return s; 
    }
};