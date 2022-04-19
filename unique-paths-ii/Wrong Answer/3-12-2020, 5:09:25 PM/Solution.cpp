// https://leetcode.com/problems/unique-paths-ii

#include <queue> 
#include <vector>
#include <utility>

using namespace std; 
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        obstacleGrid[0][0] = 1; 
    helper(obstacleGrid); 
        return obstacleGrid.back().back(); 
    }
    
    void helper(vector<vector<int> >& grid) {
        queue<pair<int, int> > q = queue<pair<int, int> >(); 
        q.push(make_pair(0, 0)); 
        
        while (!q.empty()) {
            pair<int, int> tmp = q.front(); 
            q.pop();
            if (tmp.first + 1 < grid.size() && tmp.second < grid[0].size()) {
                if (grid[tmp.first + 1][tmp.second] == 0) {
                    q.push(make_pair(tmp.first + 1, tmp.second)); 
                }
                grid[tmp.first + 1][tmp.second] += grid[tmp.first][tmp.second]; 
                
            }
            if (tmp.first < grid.size() && tmp.second + 1 < grid[0].size()) {
                if (grid[tmp.first][tmp.second + 1] == 0) {
                    q.push(make_pair(tmp.first, tmp.second + 1)); 
                }
                grid[tmp.first][tmp.second + 1] += grid[tmp.first][tmp.second]; 
            }
        }
        
    }
};