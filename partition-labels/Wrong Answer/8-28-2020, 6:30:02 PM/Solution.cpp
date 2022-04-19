// https://leetcode.com/problems/partition-labels

class Solution {
public:
    vector<int> partitionLabels(string s) {
        array<int, 26> latest; fill(latest.begin(), latest.end(), INT_MIN);
        for (int i = 0; i < s.length(); ++i) {
            latest[s[i] - 'a'] = max(latest[s[i] - 'a'], i); 
        }
        vector<int> ans; 
        int curmax = latest[s[0] - 'a']; 
        int curlen = 1; 
        for (int i = 0; i < s.length(); ++i) {
            if (i == curmax) {
                ans.push_back(curlen); 
                curlen = 1; 
            } else {
                curmax = max(curmax, latest[s[i] - 'a']); 
                ++curlen; 
            }
        }
        return ans; 
    }
};