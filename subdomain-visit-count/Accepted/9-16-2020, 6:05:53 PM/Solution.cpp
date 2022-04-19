// https://leetcode.com/problems/subdomain-visit-count

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> ct; 
        for (string s : cpdomains) {
            int idx = s.find(" ");
            int add = stoi(s.substr(0, idx)); 
            string dom = "." + s.substr(idx + 1); 
            
            for (int i = 0; i < dom.length(); ++i) {
                if (dom[i] == '.') {
                    ct[dom.substr(i + 1)] += add; 
                }
            }
        }
        
        vector<string> ans; 
        for (auto p : ct) {
            ans.push_back(to_string(p.second) + " " + p.first); 
        }
        return ans; 
    }
};