// https://leetcode.com/problems/jump-game-iv

class Solution {
public:
    int minJumps(vector<int>& arr) {
        const int n = arr.size();
        unordered_map<int,vector<int>> graph;
        for (int i = 0; i < n; ++i) {
            graph[arr[i]].push_back(i);
        }
        
        vector<bool> visited(n, false);
        
        queue<pair<int,int>> bfsq;
        
        bfsq.push({0, 0});
        
        while(!bfsq.empty()) {
            auto [idx, dist] = bfsq.front();

            bfsq.pop();

            
            // if (idx < 0 || idx >= n || visited[idx]) { continue; }
            if (idx == n - 1) {
                return dist;
            }
            visited[idx] = true;
            if (idx + 1 < n)
                bfsq.push({idx + 1, dist + 1});
            
            if (idx > 1)
                bfsq.push({idx - 1, dist + 1});
            
            for (int x : graph[arr[idx]]) {
                if (x == idx) continue;
                bfsq.push({x, dist + 1});
            }
            
        }
        
        
        return -1;
        
        
    }
};