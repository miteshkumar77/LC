// https://leetcode.com/problems/longest-valid-parentheses

class Solution {
public:
    int longestValidParentheses(string s) {
        int sum = 0; 
        int last_idx = 0; 
        int longest_string = 0; 
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ')') {
                --sum; 
            } else {
                ++sum; 
            }
            
            if (sum < 0) {
                sum = 0; 
                last_idx = i + 1; 
            } else if (sum == 0) {
                if (i - last_idx + 1 > longest_string) {
                    longest_string = i - last_idx + 1; 
                }
            }
        }
        
        sum = 0; 
        last_idx = s.length() - 1; 
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[i] == '(') {
                --sum; 
            } else {
                ++sum; 
            }
            
            if (sum < 0) {
                sum = 0; 
                last_idx = i - 1; 
            } else if (sum == 0) {
                if (last_idx - i + 1 > longest_string) {
                    longest_string = last_idx - i + 1; 
                }
            }
        }
        return longest_string; 
    }
};