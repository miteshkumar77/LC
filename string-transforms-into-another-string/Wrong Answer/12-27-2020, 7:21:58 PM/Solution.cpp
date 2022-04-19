// https://leetcode.com/problems/string-transforms-into-another-string

class Solution {
public:
    bool canConvert(string str1, string str2) {
        if (str1 == str2) return true;
        int n = str1.length();
        unordered_map<char,char> ch;
        for (int i = 0; i < n; ++i) {
            if (ch.find(str1[i]) != ch.end() && ch[str1[i]] != str2[i]) return false;
            ch[str1[i]] = str2[i];
        }
        
        if (ch.size() == 26) return false;
        return true;
    }
};