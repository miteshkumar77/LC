// https://leetcode.com/problems/longest-palindrome

class Solution {
public:
    int longestPalindrome(string s) {
        array<int, 256> chars; 
        fill(chars.begin(), chars.end(), 0); 
        for (char c : s) {
            ++chars[c]; 
        }
        
        bool isOdd = false; 
        int ans = 0; 
        for (int i = 0; i < 256; ++i) {
            if (chars[i] & 1) {
                isOdd = true; 
                ans += chars[i] - 1; 
            } else {
                ans += chars[i]; 
            }
        }
        ans += isOdd; 
        return ans; 
    }
};