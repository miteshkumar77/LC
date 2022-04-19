// https://leetcode.com/problems/roman-to-integer

class Solution {
public:
    int romanToInt(string s) {
        array<int, 256> mp; 
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        
        int ans = 0;
        int prev = INT_MAX;
        for (char c : s) {
            if (prev < mp[c]) {
                ans += mp[c] - prev - prev;
            } else {
                ans += mp[c];
            }
            prev = mp[c];
        }
        return ans;
    }
};

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000