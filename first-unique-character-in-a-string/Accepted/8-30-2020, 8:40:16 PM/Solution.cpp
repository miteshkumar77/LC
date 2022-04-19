// https://leetcode.com/problems/first-unique-character-in-a-string

class Solution {
public:
    int firstUniqChar(string s) {
        array<int, 256> ct; 
        fill(ct.begin(), ct.end(), 0); 
        for (char c : s) ++ct[c]; 
        for (int i = 0; i < s.length(); ++i) {
            if (ct[s[i]] == 1) {
                return i; 
            }
        }
        return -1; 
    }
};