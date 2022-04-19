// https://leetcode.com/problems/course-schedule-iv

class Solution {
public:
    
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n);
        for (auto& e : prerequisites) {
            graph[e[0]].push_back(e[1]);
        }
        vector<vector<bool>> parent(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            queue<int> bfsq;
            bfsq.push(i);
            while(!bfsq.empty()) {
                if (parent[i][bfsq.front()]) {bfsq.pop(); continue;}
                parent[i][bfsq.front()] = true;
                for (int j : graph[bfsq.front()]) {
                    bfsq.push(j);
                }
                bfsq.pop();
            }
        }
        
        vector<bool> ans;
        ans.reserve(queries.size());
        for (auto& q : queries) {
            ans.push_back(parent[q[0]][q[1]]);
        }
        return ans;
    }
};