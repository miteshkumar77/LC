// https://leetcode.com/problems/number-of-provinces

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        vector<bool> visited(M.size(), false); 
        
        int ans = 0; 
        
        
        function<void(int)> dfs = [&] (int student) -> void {
            visited[student] = true; 
            for (int f = 0; f < M.size(); ++f) {
                if (M[student][f] == 1 && !visited[f]) {
                    dfs(f); 
                }
            }  
        };
        
        
        for (int student = 0; student < M.size(); ++student) {
            if (!visited[student]) {
                ++ans; 
                dfs(student); 
            }
        }
        return ans; 
    }
};