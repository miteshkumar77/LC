// https://leetcode.com/problems/decode-string

class Solution {
public:
    string decodeString(string s) {
        function<pair<string, int>(int)> bt = [&](int begin) -> pair<string,int> {
            string ret = "";
            string mult = ""; 
            for (int i = begin; i < s.length(); ++i) {
                if (s[i] == '[') {
                    int m = stoi(mult); 
                    auto p = bt(i + 1);
                    i = p.second;
                    for (int x = 0; x < m; ++x) {
                        ret += p.first;
                    }
                    mult = "";
                } else if (s[i] == ']') {
                    return make_pair(ret, i); 
                } else if (s[i] >= '0' && s[i] <= '9') {
                    mult += s[i]; 
                } else {
                    ret += s[i];
                }
            }
            return make_pair(ret, s.length());
        };
        
        return bt(0).first;
    }
};