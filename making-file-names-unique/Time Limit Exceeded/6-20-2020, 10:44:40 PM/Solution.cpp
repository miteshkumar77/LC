// https://leetcode.com/problems/making-file-names-unique

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_set<string> c; 
        vector<string> ans; ans.reserve(names.size()); 
        
        for (string s : names) {
            if (c.find(s) == c.end()) {
                c.insert(s); 
                ans.push_back(s); 
            } else {
                int ct = 1; 
                while(c.find(s + "(" + to_string(ct) + ")") != c.end()) {
                    ++ct; 
                }
                c.insert(s + "(" + to_string(ct) + ")"); 
                ans.push_back(s + "(" + to_string(ct) + ")"); 
            }
        }
        return ans; 
        
    }
};