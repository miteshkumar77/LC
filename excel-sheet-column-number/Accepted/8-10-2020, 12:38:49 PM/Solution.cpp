// https://leetcode.com/problems/excel-sheet-column-number

class Solution {
public:
    int titleToNumber(string s) {
        
        unsigned long long int base = 1; 
        int ans = 0; 
        for (int i = s.length() - 1; i >= 0; --i) {
            ans += (s[i] - 'A' + 1) * base; 
            base *= 26; 
        }
        return ans; 
    }
};