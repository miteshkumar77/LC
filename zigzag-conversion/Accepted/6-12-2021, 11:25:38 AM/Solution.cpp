// https://leetcode.com/problems/zigzag-conversion

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> zigzag(numRows, "");
        
        int dir = 1;
        int i = 0;
        for (char c : s) {
            zigzag[i].push_back(c);
            if ((i == 0 && dir == -1) || (i == numRows-1 && dir == 1)) {
                dir = (-1) * dir;
            }
            i += dir;
        }
        string ans;
        for (string& s : zigzag) ans += s;
        return ans;
        // return accumulate(zigzag.begin(), zigzag.end(), "");
    }
};