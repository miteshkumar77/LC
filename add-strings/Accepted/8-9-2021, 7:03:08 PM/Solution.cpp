// https://leetcode.com/problems/add-strings

class Solution {
public:
    string addStrings(string a, string b) {
        reverse(a.begin(), a.end()); reverse(b.begin(), b.end());
        string s; s.reserve(max(a.length(), b.length()));
        int i = 0; int j = 0; int ival, jval; 
        int carry = 0;
        while(i < a.length() || j < b.length() || carry) {
            ival = (i < a.length()) ? (a[i] - '0') : 0; ++i;
            jval = (j < b.length()) ? (b[j] - '0') : 0; ++j;
            s.push_back(((carry + ival + jval) % 10) + '0');
            carry = (carry + ival + jval)/10;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};