// https://leetcode.com/problems/maximum-binary-string-after-change

class Solution {
public:
    string maximumBinaryString(string binary) {
        int num_zeros = 0;
        for (int i = 0; i < binary.size(); ++i) {
            num_zeros += binary[i] == '0'?1:0;
        }
        string ans;
        for (int i = 0; i < binary.size() && binary[i] == '1'; ++i) {
            ans += '1';
        }
        while(num_zeros > 1) {ans += '1'; --num_zeros;}
        if (num_zeros) ans += '0'; 
        while(ans.size() < binary.size()) ans += '1';
        return ans;
    }
};