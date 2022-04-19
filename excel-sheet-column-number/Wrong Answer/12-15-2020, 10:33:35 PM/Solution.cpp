// https://leetcode.com/problems/excel-sheet-column-number

class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        reverse(s.begin(), s.end());
        int pow = 1;
        for (int i = 0; i < s.length(); ++i) {
            ans += pow * (s[i] - 'A'); 
        }
        return ans + 1;
    }
};