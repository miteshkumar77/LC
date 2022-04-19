// https://leetcode.com/problems/reverse-words-in-a-string-ii

class Solution {
public:
    void rev(int l, int r, vector<char>& s) {
       while(l < r) {
           swap(s[l++], s[r--]);
       }
    }

    void reverseWords(vector<char>& s) {
        int prev = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') {
                rev(prev, i-1, s);
                prev = i + 1;
            }
        }
        rev(prev, n-1, s);
        rev(0, n-1, s);
    }
};