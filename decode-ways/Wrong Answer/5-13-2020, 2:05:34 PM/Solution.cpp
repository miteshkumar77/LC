// https://leetcode.com/problems/decode-ways

class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0; 
        }
        unsigned long long int accumulator_0 = 0;
        unsigned long long int accumulator_1 = 1; 
        
        int tmp = 0; 
        for (int i = 0; i < s.length(); ++i) {
            if (i >= 1 && s[i] == '0' && s[i - 1] == '0') {
                return 0; 
            }
            tmp = 0; 
            if (s[i] != 0) {
                tmp += accumulator_1; 
            }
            
            if (i >= 1 && (int)(s[i - 1] - '0') * 10 - (int)(s[i] - '0') <= 26 && 
                (int)(s[i - 1] - '0') * 10 - (int)(s[i] - '0') >= 1 && 
               s[i - 1] != '0') {
                tmp += accumulator_0; 
            }
            
            accumulator_0 = accumulator_1; 
            accumulator_1 = tmp; 
        }
        
        return tmp; 
    }
};