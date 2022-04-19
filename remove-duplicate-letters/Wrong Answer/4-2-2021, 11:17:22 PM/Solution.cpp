// https://leetcode.com/problems/remove-duplicate-letters

class Solution {
public:
    string removeDuplicateLetters(string s) {
        array<int, 26> ct;
        fill(ct.begin(), ct.end(), 0);
        for (char c : s) {
            ++ct[c - 'a'];
        }
        string ans;
        for (char c : s) {
            if (ct[c - 'a'] != 1) {
                --ct[c - 'a'];

                for (int i = 0; i < 26; ++i) {
                    if (ct[i] > 0) {
                        ct[i] = 0;
                        ans.push_back(i + 'a');
                        break;
                    }
                }
            } else if (ct[c - 'a'] == 1) {
                ct[c - 'a'] = 0;
                ans.push_back(c);
            }
        }
        return ans;
    }
};