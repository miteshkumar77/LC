// https://leetcode.com/problems/remove-all-occurrences-of-a-substring

class Solution {
public:
    string removeOccurrences(string s, string part) {
        string stk;
        for (char c : s) {
            stk.push_back(c);
            if (stk.length() >= part.length() && stk.substr(stk.length() - part.length(), part.length()) == part) {
                stk = stk.substr(0, stk.length() - part.length());
            }
        }
        return stk;
    }
};