// https://leetcode.com/problems/construct-k-palindrome-strings

class Solution {
public:
    bool canConstruct(string s, int k) {
        array<int, 26> ct;
        fill(ct.begin(), ct.end(), 0);
        for (char c : s) ++ct[c-'a'];
        int non_even = 0;
        int num_total = 0;
        for (int i : ct) {
            non_even += (i % 2);
            num_total += i;
        }
        if (non_even > k || (num_total < k)) {
            return false;
        }
        return true;
    }
};