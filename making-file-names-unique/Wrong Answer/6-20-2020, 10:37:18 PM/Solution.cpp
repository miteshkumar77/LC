// https://leetcode.com/problems/making-file-names-unique

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> ct; 
        vector<string> ans; ans.reserve(names.size()); 
        
        for (string s : names) {
            ct[s]++; 
            if (ct[s] != 1) {
                ans.push_back(s + "(" + to_string(ct[s] - 1) + ")");
            } else {
                ans.push_back(s); 
            }
        }
        return ans; 
    }
};