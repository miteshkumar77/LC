// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length

class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        int size = 0;
        int vowels = 0;
        int ans = 0;
        int j;
        for (int i = 0; i < n; ++i) {
            vowels += (s[i] == 'a' || s[i] == 'o' || s[i] == 'e' || s[i] == 'i' || s[i] == 'u');
            size = min(k, size + 1);
            ans = max(ans, vowels);
            if (size == k) {
                j = i;
                i = j - k + 1;
                vowels -= (s[i] == 'a' || s[i] == 'o' || s[i] == 'e' || s[i] == 'i' || s[i] == 'u');
                i = j;
            }
        }
        return ans;
    }
};