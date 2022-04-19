// https://leetcode.com/problems/evaluate-division

class Solution {
public:
    typedef pair<string,string> pss; 
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string,double>> graph; 
        for (int i = 0; i < equations.size(); ++i) {
            graph[equations[i][0]][equations[i][1]] = values[i]; 
            graph[equations[i][0]][""] = 1;
            graph[equations[i][1]][equations[i][0]] = 1 / values[i]; 
            graph[equations[i][1]][""] = 1;
        }
        
        
        function<double(string,string)> eval = [&](string a, string b) -> double {
            if (graph.find(a) == graph.end() || graph.find(b) == graph.end()) {
                return -1; 
            }
            unordered_map<string, string> prev; 
            queue<pss> bfsq; 
            bfsq.push(pss(a, "")); 
            
            while(!bfsq.empty()) {
                string t = bfsq.front().first; string p = bfsq.front().second; 
                bfsq.pop(); 

                if (prev.find(t) != prev.end()) {
                    continue; 
                }
                prev[t] = p; 
                
                if (t == b) {
                    double ans = 1; 
                    string cur = b; 
                    while(cur != "") {
                        
                        ans *= graph[cur][prev[cur]]; 
                        cur = prev[cur]; 
                    }
                    graph[a][b] = ans;
                    return ans; 
                }
                for (auto [var, val] : graph[t]) {
                    bfsq.push(pss(var, t)); 
                }
            }
            return -1; 
        };
        
        vector<double> ans; ans.reserve(queries.size()); 
        for (auto v : queries) {
            ans.push_back(eval(v[1], v[0]));
        }
        return ans; 
    }
};