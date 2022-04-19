// https://leetcode.com/problems/simplify-path

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> tokenized_path = split(path); 
        string ans = "/"; 
        for (int i = 0; i < tokenized_path.size() - 1; ++i) {
            ans += tokenized_path[i] + "/"; 
        }
        
        if (tokenized_path.size() != 0) {
            ans += tokenized_path[tokenized_path.size() - 1]; 
        }
        return ans; 
    }
    
    
    
    vector<string> split(string& str, char delim='/') {
        vector<string> ans; 
        size_t curr, prev = 0; 
        curr = str.find(delim); 
        while(curr != string::npos) {
            string s = str.substr(prev, curr - prev); 
            if (s == "..") {
                if (ans.size() != 0) {
                    ans.pop_back(); 
                }
            } else if (s != "" && s != ".") {
                ans.push_back(s); 
            }
            prev = curr + 1; 
            curr = str.find(delim, prev); 
        }
        string s = str.substr(prev, curr - prev); 
        if (s == "..") {
            if (ans.size() != 0) {
                ans.pop_back(); 
            }
        } else if (s != "" && s != ".") {
            ans.push_back(s); 
        }
        return ans; 
    }
};