// https://leetcode.com/problems/keyboard-row

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        array<unordered_set<char>, 3> rows; 
        string r1 = "qwertyuiop"; 
        string r2 = "asdfghjkl"; 
        string r3 = "zxcvbnm"; 
        rows[0] = unordered_set<char>(r1.begin(), r1.end()); 
        rows[1] = unordered_set<char>(r2.begin(), r2.end()); 
        rows[2] = unordered_set<char>(r3.begin(), r3.end()); 
        
        vector<string> ans; 
        
        for (string w : words) {
            for (int i = 0; i < 3; ++i) {
                bool yes = true; 
                for (char c : w) {
                    if (rows[i].find(tolower(c)) == rows[i].end()) {
                        yes = false; 
                        break;
                    }
                }
                if (yes) {
                    ans.push_back(w); 
                    break;
                }
            }
        }
        return ans; 

    }
};