// https://leetcode.com/problems/largest-odd-number-in-string

class Solution {
public:
    string largestOddNumber(string num) {
        int l = 0;
        int n = num.length();
        for (int i = 0; i < n; ++i) {
            if ((num[i]-'0')%2==1) l = i+1;
        }
        return num.substr(0, l);
    }
};