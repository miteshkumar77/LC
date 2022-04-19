// https://leetcode.com/problems/partition-labels

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> latest(26, INT_MIN);
        for (int i = 0; i < s.length(); ++i) {
            latest[s[i] - 'a'] = i;
        }
        int len = 0;
        int last = 0;
        vector<int> ans;
        for (int i = 0; i < s.length(); ++i) {
            ++len;
            last = max(last, latest[s[i] - 'a']);
            if (last == i) {
                ans.push_back(len);
                len = 0;
            }
        }
        return ans;
    }
};