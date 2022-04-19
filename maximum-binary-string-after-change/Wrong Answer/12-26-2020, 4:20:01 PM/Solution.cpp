// https://leetcode.com/problems/maximum-binary-string-after-change

class Solution {
public:
    string maximumBinaryString(string binary) {
        
        
        
        bool seen_zero = false;
        int num_zeros = 0;
        int num_ones = 0;
        for (int i = 0; i < binary.length(); ++i) {
            if (binary[i] == '0') {
                ++num_zeros;
                seen_zero = true;
            }
            
            if (binary[i] == '1' && seen_zero) {
                ++num_ones;
            }
        }
        
        string ans;
        for (int i = 0; i < binary.length() && binary[i] == '1'; ++i) {
            ans.push_back(binary[i]);
        }
        
        for (int i = 0; i < num_zeros - 1; ++i) {
            ans.push_back('1');
        }
        ans.push_back('0');
        for (int i = 0; i < num_ones; ++i) {
            ans.push_back('1');
        }
        
        return ans;
        
        // for (int i = 1; i < binary.length(); ++i) {
        //     if (binary[i] == '0' && binary[i - 1] == '0') {
        //         binary[i - 1] = '1';
        //     }
        // }
        
        // return binary;
    }
};