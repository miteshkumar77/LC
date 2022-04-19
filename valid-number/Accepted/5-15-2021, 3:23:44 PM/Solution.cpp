// https://leetcode.com/problems/valid-number

class Solution {
public:
    bool isDigits(string s) {
        for (char c : s) {
            if (!isdigit(c)) {
                return false;
            }
        }
        return true;
    }
    
    bool isInteger(string s, bool lhs) {
        int off = (s[0] == '+' || s[0] == '-') ? 1 : 0;
        if (off == 1 && s.length() == 1 && !lhs) return false;
        int n = s.length();
        return isDigits(s.substr(off, n - off));
    }
    
    bool isDecimal(string s) {
        vector<string> parts{""};
        
        for (char c : s) {
            if (c == '.') {
                parts.push_back("");
            } else {
                parts.back().push_back(c);
            }
        }
        if (parts.size() > 2) return false;
        if (parts.size() == 2) {
            if ((parts[0] == "+" || parts[0] == "-") && parts[1].length() == 0) return false;
            if (parts[1].length() == 0 && parts[0].length() == 0) return false;
            return isInteger(parts[0], true) && isDigits(parts[1]);
        } else {
            if (parts[0].length() == 0) return false;
            return isInteger(parts[0], false);
        }
    }
    
    bool isNumber(string s) {
        vector<string> parts{""};
        for (char c : s) {
            if (c == 'e' || c == 'E') {
                parts.push_back("");
            } else {
                parts.back().push_back(c);
            }
        }
        if (parts.size() > 2) return false;
        if (parts.size() == 2) {
            if (parts[1].length() == 0 || parts[0].length() == 0) return false;
            return isDecimal(parts[0]) && isInteger(parts[1], false);
        } else {
            if (parts[0].length() == 0) return false;
            return isDecimal(parts[0]);
        }
    }
};