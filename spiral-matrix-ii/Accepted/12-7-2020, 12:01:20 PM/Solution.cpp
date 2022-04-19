// https://leetcode.com/problems/spiral-matrix-ii

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        /**
        0 0 0 0 
        
        **/
        vector<vector<int>> ans(n, vector<int>(n, -1));
        array<int, 5> dirs {0, 1, 0, -1, 0}; 
        int cdir = 0; 
        int n2 = n * n;
        int cr = 0;
        int cc = 0;
        for (int i = 1; i <= n2; ++i) {
            if (cr >= n || cr < 0 || cc >= n || cc < 0 || ans[cc][cr] != -1) {
                cc -= dirs[cdir];
                cr -= dirs[cdir + 1];
                cdir = (cdir + 1) % 4;
                cc += dirs[cdir]; 
                cr += dirs[cdir + 1];
            }
            ans[cc][cr] = i;
            cc += dirs[cdir];
            cr += dirs[cdir + 1];
        }
        return ans;
    }
};