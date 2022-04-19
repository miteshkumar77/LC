// https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels

class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int min_y = INT_MAX; 
        int min_x = INT_MAX; 
        int max_x = INT_MIN; 
        int max_y = INT_MIN; 
        
        array<int, 5> dirs{0, 1, 0, -1, 0}; 
        function<void(int,int)> dfs = [&](int i, int j) -> void {
            if (i < 0 || j < 0 || i >= image.size() || j >= image[i].size()) {
                return; 
            }
            if (image[i][j] == '1') {
                min_y = min(i, min_y); 
                max_y = max(i, max_y); 
                min_x = min(j, min_x); 
                max_x = max(j, max_x); 
                image[i][j] = '0'; 
                for (int x = 0; x < 4; ++x) {
                    dfs(i + dirs[x], j + dirs[x + 1]); 
                }
            } else {
                return; 
            }
        }; 
        
        dfs(x, y); 
        
        return (max_y - min_y + 1) * (max_x - min_x + 1); 
    }
};