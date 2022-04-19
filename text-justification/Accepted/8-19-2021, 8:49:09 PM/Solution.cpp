// https://leetcode.com/problems/text-justification

class Solution {
public:
    
    string pack(vector<string>& words, int len, int maxWidth, bool last) {
        int n = words.size();
        if (n == 1) {
            return words[0] + string(maxWidth - len, ' ');
        }
        string ans;
        int total_space = maxWidth - len;
        int base = (total_space)/(n-1);
        int rem = total_space - base * (n-1);
        // cout << rem << endl;
        for (int i = 0; i < n; ++i) {
            ans += words[i];
            if (i+1 < n) {
                ans += string(last ? 1 : (base + (rem-- > 0)), ' ');
            }
        }
        if (last) {
            ans += string(maxWidth - ans.length(), ' ');
        }
        return ans;
    }
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int prev = 0;
        int len = 0;
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            if (words[i].length() + len + (i - prev) > maxWidth) {
                auto sub = vector<string>(words.begin() + prev, words.begin() + i);
                ans.push_back(pack(sub, len, maxWidth, false));
                len = 0;
                prev = i;
            }
            len += words[i].length();
            
            if (i + 1 == n) {
                auto sub = vector<string>(words.begin() + prev, words.begin() + i + 1);
                ans.push_back(pack(sub, len, maxWidth, true));
            }
        }
        return ans;
    }
};