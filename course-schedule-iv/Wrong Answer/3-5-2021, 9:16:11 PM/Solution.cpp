// https://leetcode.com/problems/course-schedule-iv

class Solution {
public:
    
    void ts(vector<vector<int>>& graph, vector<int>& color, unordered_map<int,int>& mp, vector<int>& stk, int node, int c) {
        color[node] = c;
        for (int neighbor : graph[node]) {
            ts(graph, color, mp, stk, neighbor, c);
        }
        stk.push_back(node); 
        mp[node] = stk.size();
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n);
        for (auto e : prerequisites) {
            graph[e[0]].push_back(e[1]);
        }
        vector<int> stk;
        stk.reserve(n);
        vector<int> color(n, -1);
        unordered_map<int,int> mp;
        int c = 0;
        for (int i = 0; i < n; ++i) {
            if (color[i] == -1) {
                ts(graph, color, mp, stk, i, c++);
            }
        }
        vector<bool> res;
        res.reserve(n);
        for (auto& q : queries) {
            res.push_back(mp[q[0]] > mp[q[1]] && color[q[0]] == color[q[1]]);
        }
        return res;
        
    }
};