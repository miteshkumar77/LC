// https://leetcode.com/problems/partition-labels

class Solution {
public:
    vector<int> partitionLabels(string S) {
        array<int, 26> last; fill(last.begin(), last.end(), INT_MIN); 
        for (int i = 0; i < S.length(); ++i) {
            last[S[i] - 'a'] = max(last[S[i] - 'a'], i); 
        }
        
        vector<int> ans; 
        int latest = INT_MIN;
        int size = 0; 
        for (int i = 0; i < S.length(); ++i) {
            latest = max(latest, last[S[i] - 'a']); 
            ++size; 
            if (i == latest) {
                ans.push_back(size); 
                latest = INT_MIN; 
                size = 0; 
            }
        }
        return ans; 
    }
};