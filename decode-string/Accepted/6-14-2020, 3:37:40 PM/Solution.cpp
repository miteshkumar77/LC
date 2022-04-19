// https://leetcode.com/problems/decode-string

class Solution {
public:
    string decodeString(string s) {
        return helper(s, 0).first; 
    }
    
    
    pair<string, int> helper(string& s, int i) {
        string res = ""; 
        while(i < s.length() && s[i] != ']' ) {
            if (!isdigit(s[i])) {
                res += s[i]; 
                ++i;
            } else {
                string num = ""; 
                while(s[i] != '[') {
                    num += s[i]; 
                    ++i; 
                }
                pair<string, int> sub = helper(s, i + 1); 
                for (int x = 0; x < stoi(num); ++x) {
                    res += sub.first; 
                }
                i = sub.second; 
            }
        }
        return make_pair(res, i + 1);  
    }
};