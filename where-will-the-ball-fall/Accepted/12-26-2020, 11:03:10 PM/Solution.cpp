// https://leetcode.com/problems/where-will-the-ball-fall

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> ballz(n);
        for (int i = 0; i < n; ++i) {
            ballz[i] = i;
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {

                if (ballz[j] == -1) continue;
                int last = grid[i][ballz[j]];


                ballz[j] += grid[i][ballz[j]];
                // cout << ballz[j] << ' ';

                ballz[j] = ballz[j] >= n?-1:ballz[j];
                if (ballz[j] != -1) {
                    // cout << i << ' ' << grid[i][ballz[j]] << ' ' << last << endl;
                    if (grid[i][ballz[j]] != last) {
                        ballz[j] = -1;
                    }
                }
                
                
            }
            // cout << endl;
        }
        
        return ballz;
    }
};


/** [[1,1,1,-1,-1],
     [1,1,1,-1,-1],
     [-1,-1,-1,1,1],
     [1,1,1,1,-1],
     [-1,-1,-1,-1,-1]] */