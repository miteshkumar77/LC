// https://leetcode.com/problems/excel-sheet-column-number

class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        reverse(s.begin(), s.end());
        int pow = 1;
        for (int i = 0; i < s.length(); ++i) {
            ans += pow * (s[i] - 'A'); 
            // if (i != s.length() - 1) {
                pow *= 26;
            // }
        }
        return ans + 1;
    }
};