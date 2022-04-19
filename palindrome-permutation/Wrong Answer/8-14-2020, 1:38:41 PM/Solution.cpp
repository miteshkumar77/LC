// https://leetcode.com/problems/palindrome-permutation

class Solution {
public:
    bool canPermutePalindrome(string s) {
        array<int, 256> cts; 
        for (char c : s) {
            ++cts[c]; 
        }
        int num_odd = 0; 
        for (int i = 0; i < 256; ++i) {
            if (cts[i] & 1) {
                ++num_odd; 
                if (num_odd > 1) {
                    return false; 
                }
            }
            
        }
        
        return true; 
    }
};