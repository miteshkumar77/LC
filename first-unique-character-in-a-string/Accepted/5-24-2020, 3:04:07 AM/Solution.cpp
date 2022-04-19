// https://leetcode.com/problems/first-unique-character-in-a-string

class Solution {
public:
    int firstUniqChar(string s) {
        array<int, 26> duplicate{0}; 
        
        for (char c : s) {
            ++duplicate[c - 'a'];
        }
        for (int i = 0; i < s.length(); ++i) {
            if (duplicate[s[i] - 'a'] == 1) {
                return i; 
            }
        }
        return -1; 
    }
};