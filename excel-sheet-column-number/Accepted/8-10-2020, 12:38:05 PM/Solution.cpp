// https://leetcode.com/problems/excel-sheet-column-number

class Solution {
public:
    int titleToNumber(string s) {
        array<int, 26> alph; 
        for (int i = 0; i < 26; ++i) {
            alph[i] = i + 1; 
        }
        unsigned long long int base = 1; 
        int ans = 0; 
        for (int i = s.length() - 1; i >= 0; --i) {
            ans += alph[s[i] - 'A'] * base; 
            base *= 26; 
        }
        return ans; 
    }
};