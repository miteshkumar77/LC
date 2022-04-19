// https://leetcode.com/problems/determine-if-string-halves-are-alike

class Solution {
public:
    
    bool checkVowel(char c ) {
        string vwls = "aeiouAEIOU";
        return vwls.find(string(1, c)) != string::npos;
    }
    bool halvesAreAlike(string s) {
        int v1 = 0;
        for (int i = 0; i < s.length()/2; ++i) {
            v1 += checkVowel(s[i]);
        }
        int v2 = 0;
        for  (int i = s.length()/2; i < s.length(); ++i) {
            v2 += checkVowel(s[i]);
        }
        
        return v1 == v2;
    }
};