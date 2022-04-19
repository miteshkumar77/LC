// https://leetcode.com/problems/decode-ways

class Solution {
public:
    int numDecodings(string s) {
        unsigned long long int accumulator_0 = 0;
        unsigned long long int accumulator_1 = 1; 
        int i = 0; 
        while(s[i] == '0') { ++i; }
        int tmp; 
        for ( ; i < s.length(); ++i) {
            tmp = 0; 
            if (s[i] != 0) {
                tmp += accumulator_1; 
            }
            
            if (i >= 1 && (int)(s[i - 1] - '0') * 10 - (int)(s[i] - '0') <= 26 && (int)(s[i - 1] - '0') * 10 - (int)(s[i] - '0') >= 1) {
                tmp += accumulator_0; 
            }
            
            accumulator_0 = accumulator_1; 
            accumulator_1 = tmp; 
        }
        
        return accumulator_1; 
    }
};