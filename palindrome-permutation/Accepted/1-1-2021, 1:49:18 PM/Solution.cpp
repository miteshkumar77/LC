// https://leetcode.com/problems/palindrome-permutation

class Solution {
public:
    bool canPermutePalindrome(string s) {
        array<int, 256> ct; fill(ct.begin(), ct.end(), 0);
        for (char c : s) {
            ++ct[c];
        }
        int num_odd = 0;
        for (int i : ct) {
            num_odd += i % 2;
            if (num_odd == 2) {
                return false;
            }
        }
        return true;
    }
};