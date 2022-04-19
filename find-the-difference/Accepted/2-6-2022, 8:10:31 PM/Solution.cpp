// https://leetcode.com/problems/find-the-difference

class Solution {
public:
    char findTheDifference(string s, string t) {
        char cr = 0;
        for (char c : s) cr ^= c;
        for (char c : t) cr ^= c;
        return cr;
    }
};