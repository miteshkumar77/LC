// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (t.length() != s.length()) return false;
        array<int, 26> ct;
        fill(ct.begin(), ct.end(), 0); 
        for (char c : s) {
            ++ct[c - 'a'];
        }
        for (char c : t) {
            --ct[c - 'a'];
        }
        for (int i : ct) if (i != 0) return false;
        return true;
    }
};