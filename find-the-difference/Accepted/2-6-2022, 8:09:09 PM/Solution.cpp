// https://leetcode.com/problems/find-the-difference

class Solution {
public:
    char findTheDifference(string s, string t) {
        array<int, 26> ct{};
        for (char c : t) ++ct[c-'a'];
        for (char c : s) --ct[c-'a'];
        for (int i = 0; i < 26; ++i) if (ct[i] > 0) return i+'a';
        return 26;
    }
};