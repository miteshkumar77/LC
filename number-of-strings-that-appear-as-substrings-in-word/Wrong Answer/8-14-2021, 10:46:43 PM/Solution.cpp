// https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for (string const & p : patterns) {
            for (int i = 0; i < word.length(); ++i) {
                bool match = true;
                for (int j = 0, k = i; j < p.length() && k < word.length(); ++j, ++k) {
                    if (p[j] != word[k]) {
                        match = false;
                        break;
                    }
                }
                if (match) ++ans;
                break;
            }
        }
        return ans;
    }
};