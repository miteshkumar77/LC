// https://leetcode.com/problems/course-schedule-iv

class Solution {
public:
    
    bool isParent(vector<vector<int>>& graph, int node, int child, vector<vector<int>>& pars) {
        if (pars[node][child]!= -1) {
            return pars[node][child];
        }
        if (pars[child][node]!= -1) {
            return !pars[child][node];
        }
        if (node == child) return true;
        for (int neighbor : graph[node]) {
            if (isParent(graph, neighbor, child, pars)) {
                pars[node][child] = 1;
                return true;
            }
        }
        pars[node][child] = -1;
        return false;
    }
    
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n);
        for (auto& e : prerequisites) {
            graph[e[0]].push_back(e[1]);
        }
        vector<vector<int>> pars(n, vector<int>(n, -1)); 
        
        vector<bool> ans;
        ans.reserve(queries.size()); 
        for (auto e : queries) {
            
            ans.push_back(isParent(graph, e[0], e[1], pars));
        }
        return ans;
        
        
    }
};