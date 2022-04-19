// https://leetcode.com/problems/kill-process

class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        int n = pid.size(); 
        unordered_map<int,unordered_set<int>> children;
        for (int i = 0; i < n; ++i) {
            children[ppid[i]].insert(pid[i]); 
        }
        vector<int> ans; 
        queue<int> bfs;
        bfs.push(kill);
        while(!bfs.empty()) {
            int top = bfs.front();
            ans.push_back(top); 
            bfs.pop(); 
            for (int child : children[top]) {
                bfs.push(child);
            }
        }
        return ans;
    }
};