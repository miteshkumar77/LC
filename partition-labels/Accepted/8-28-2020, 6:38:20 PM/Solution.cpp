// https://leetcode.com/problems/partition-labels

class Solution {
public:
    vector<int> partitionLabels(string s) {
        array<int, 26> latest; fill(latest.begin(), latest.end(), INT_MIN);
        for (int i = 0; i < s.length(); ++i) {
            latest[s[i] - 'a'] = max(latest[s[i] - 'a'], i); 
        }
        vector<int> ans; 
        int curmax = INT_MIN; 
        int curlen = 0; 
        for (int i = 0; i < s.length(); ++i) {
            ++curlen; 
            if (latest[s[i] - 'a'] > curmax) {
                curmax = latest[s[i] - 'a']; 
            }
            if (i == curmax) {
                ans.push_back(curlen); 
                curlen = 0; 
            }
        }
        return ans; 
    }
};