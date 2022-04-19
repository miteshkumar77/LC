// https://leetcode.com/problems/unique-paths-ii

// #include <queue> 
// #include <vector>
// #include <utility>

// using namespace std; 
// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         if (obstacleGrid.size() == 0 || (obstacleGrid.size() == 1 && obstacleGrid[0].size() == 1 && obstacleGrid[0][0] == 1)) {
//             return 0;
//         }
//         if (obstacleGrid.back().back() == 1 || obstacleGrid[0][0] == 1) {
//             return 0; 
//         }
//         obstacleGrid[0][0] = 1; 
//         helper(obstacleGrid); 
//         return obstacleGrid.back().back(); 
//     }
    
//     void helper(vector<vector<int> >& grid) {
//         queue<pair<size_t, size_t> > q = queue<pair<size_t, int> >(); 
//         q.push(make_pair(0, 0)); 
        
//         while (!q.empty()) {
//             pair<int, int> tmp = q.front(); 
//             q.pop();
//             if (tmp.first + 1 < grid.size() && tmp.second < grid[0].size()) {
//                 if (grid[tmp.first + 1][tmp.second] == 0) {
//                     q.push(make_pair(tmp.first + 1, tmp.second)); 
//                 }
//                 grid[tmp.first + 1][tmp.second] += grid[tmp.first][tmp.second]; 
                
//             }
//             if (tmp.first < grid.size() && tmp.second + 1 < grid[0].size()) {
//                 if (grid[tmp.first][tmp.second + 1] == 0) {
//                     q.push(make_pair(tmp.first, tmp.second + 1)); 
//                 }
//                 grid[tmp.first][tmp.second + 1] += grid[tmp.first][tmp.second]; 
//             }
//         }
        
//     }
// };

#include <queue> 
#include <vector>
#include <utility>

using namespace std; 
class Solution {
public:
    size_t uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0 || (obstacleGrid.size() == 1 && obstacleGrid[0].size() == 1 && obstacleGrid[0][0] == 1)) {
            return 0;
        }
        if (obstacleGrid.back().back() == 1 || obstacleGrid[0][0] == 1) {
            return 0; 
        }
        obstacleGrid[0][0] = 1; 
        helper(obstacleGrid); 
        return obstacleGrid.back().back(); 
    }
    
    void helper(vector<vector<int> >& grid) {
        queue<pair<size_t, size_t> > q = queue<pair<size_t, size_t> >(); 
        q.push(make_pair(0, 0)); 
        
        while (!q.empty()) {
            pair<size_t, size_t> tmp = q.front(); 
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