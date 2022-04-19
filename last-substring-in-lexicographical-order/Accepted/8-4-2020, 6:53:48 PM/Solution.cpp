// https://leetcode.com/problems/last-substring-in-lexicographical-order

class Solution {
public:
    string lastSubstring(string s) {
        vector<int> maxsubstr(s.length()); 
        for (int i = 0; i < s.length(); ++i) {
            maxsubstr[i] = i; 
        }
        int x = 0; 
        while(maxsubstr.size() != 1) {
            char maxc = s[maxsubstr[0] + x]; 
            for (int i = 0; i < maxsubstr.size(); ++i) {
                if (maxsubstr[i] + x < s.length()) {
                    maxc = max(maxc, s[maxsubstr[i] + x]);
                }
            }
            vector<int> nextSubstr; 
            for (int i = 0; i < maxsubstr.size(); ++i) {
                if (maxsubstr[i] + x < s.length() && s[maxsubstr[i] + x] == maxc && (nextSubstr.size() == 0 || nextSubstr.back() + x < maxsubstr[i])) {
                    nextSubstr.push_back(maxsubstr[i]); 
                } 
            }
            ++x; 
            maxsubstr.swap(nextSubstr); 
        }
        
        return s.substr(maxsubstr.back(), s.length() - maxsubstr.back()); 
    }
};