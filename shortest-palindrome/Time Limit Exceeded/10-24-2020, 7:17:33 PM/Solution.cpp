// https://leetcode.com/problems/shortest-palindrome

class Solution {
public:
    bool isPal(string& s) {
        int i = 0;
        int j = s.length() - 1;
        while(i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
    string shortestPalindrome(string s) {
        for (int j = 0; j <= s.length(); ++j) {
            string tmp = s.substr(s.length() - j);
            reverse(tmp.begin(), tmp.end());
            tmp = tmp + s;
            if (isPal(tmp)) return tmp;
            
        }
        return "";
    
    }
};