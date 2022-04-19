// https://leetcode.com/problems/accounts-merge

class Solution {
public:
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, unordered_set<string>> graph;
        for (auto acct : accounts) {
            for (int i = 2; i < acct.size(); ++i) {
                graph[acct[i]].insert(acct[i - 1]);
                graph[acct[i - 1]].insert(acct[i]);
            }
        }
        
        unordered_set<string> visited; 

        function<set<string>(string)> getAll = [&](string e1) -> set<string> {
            
            queue<string> q; 
            q.push(e1); 
            set<string> ret; 
            
            while(!q.empty()) {
                string top = q.front(); q.pop(); 
                if (visited.find(top) != visited.end()) {
                    continue;
                }
                visited.insert(top);
                ret.insert(top);
                for (string neighbor : graph[top]) {
                    q.push(neighbor);
                }
            }
            return ret;
            
        };
        
        vector<vector<string>> ans;
        for (auto v : accounts) {
            if (v.size() == 1) {
                // ans.push_back(v);
                continue;
            } else if (visited.find(v[1]) == visited.end()) {
                set<string> accts = getAll(v[1]);
                vector<string> tmp{v[0]};
                for (auto s : accts) {
                    tmp.push_back(s);
                }
                ans.push_back(tmp);
            }
        }
        
        return ans;
    }
};