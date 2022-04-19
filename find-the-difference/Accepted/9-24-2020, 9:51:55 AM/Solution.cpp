// https://leetcode.com/problems/find-the-difference

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> ct; 
        for (char c : t) {
            ++ct[c];
        }
        for (char c : s) {
            --ct[c]; 
            if (ct[c] == 0) {
                ct.erase(c); 
            }
        }
        return ct.begin() -> first; 
    }
};