// https://leetcode.com/problems/length-of-last-word

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0; 
        int last = 0; 
        for (char c : s) {
            if (c == ' ') {
                if (len != 0) {
                    last = len;
                }
                len = 0; 
            } else {
                ++len; 
            }
        }
        return last; 
    }
};