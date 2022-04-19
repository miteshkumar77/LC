// https://leetcode.com/problems/number-of-distinct-islands

class Solution {
public:
    
    array<char, 4> letters{'%', '>', '|', '`'};
    array<int, 5> dirs{0, 1, 0, -1, 0};
    
    void dfs(vector<vector<int>>& grid, string& path, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return;
        if (grid[i][j] == 0) return;
        grid[i][j] = 0;
        for (int x = 0; x < 4; ++x) {
            path.push_back(letters[x]);
            dfs(grid, path, i + dirs[x], j + dirs[x + 1]);
        }
    }
    
    int numDistinctIslands(vector<vector<int>>& grid) {
        unordered_set<string> uniques;
        
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j]) {
                    string path = "";
                    dfs(grid, path, i, j);
                    uniques.insert(path);
                }
            }
        }
        return uniques.size(); 
    }
};