// https://leetcode.com/problems/count-vowels-permutation

class Solution {
public:
    
    int M = 1e9 + 7;
    vector<vector<int>> mult(const vector<vector<int>>& a, const vector<vector<int>>& b) {
        int n = a.size();
        int p = a[0].size();
        int m = b[0].size(); 
        vector<vector<int>> r(n, vector<int>(p, 0)); 
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < p; ++k) {
                    r[i][j] = (r[i][j] + (a[i][k] * b[k][j]) % M) % M; 
                }
            }
        }
        return r;
        
    }
    int countVowelPermutation(int n) {
        --n;
        vector<vector<int>> T{
            {1},
            {1},
            {1},
            {1},
            {1}
        };
        vector<vector<int>> B{
            vector<int>{0,1,1,0,1},
            {1,0,1,0,0},
            {0,1,0,1,0},
            {0,0,1,0,0},
            {0,0,1,1,0}
        };
        
        
        vector<vector<int>> R{
            vector<int>{1,0,0,0,0},
            {0,1,0,0,0},
            {0,0,1,0,0},
            {0,0,0,1,0},
            {0,0,0,0,1}
        };
        
        while(n) {
            if (n % 2 == 0) {
                n >>= 1;
                B = mult(B, B);
            } else {
                --n;
                R = mult(R, B);
            }
        }
        T = mult(R, T);
        int ans = 0;
        for (int i = 0; i < T.size(); ++i) {
            ans = (ans + T[i][0]) % M;
        }
        return ans;
        
        
    }
};