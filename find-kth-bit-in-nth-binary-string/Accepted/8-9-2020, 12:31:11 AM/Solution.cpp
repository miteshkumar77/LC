// https://leetcode.com/problems/find-kth-bit-in-nth-binary-string

class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "01"; 
        int R = s.length() - 2; 
        k -= 1; 
        while(k > s.length() -1) {
            if (R == -1) {
                R = s.length() - 1; 
                s += "1"; 
            } else {
                if (s[R--] == '1') {
                    s += '0'; 
                } else {
                    s += '1'; 
                }
            }
        }
        return s[k]; 
    }
};