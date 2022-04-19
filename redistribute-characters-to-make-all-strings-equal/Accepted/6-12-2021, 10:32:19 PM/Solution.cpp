// https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> ct(26, 0);
        for (const string& s : words) {
            for (char c : s) {
                ++ct[c-'a'];
            }
        }
        for (int i : ct) {
            if (i % words.size() != 0) return false;
        }
        return true;
    }
};