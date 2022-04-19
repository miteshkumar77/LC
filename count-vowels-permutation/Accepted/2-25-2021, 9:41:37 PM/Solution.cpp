// https://leetcode.com/problems/count-vowels-permutation

class Solution {
public:
    typedef unsigned long long int ulli;
    int M = 1e9 + 7;
    vector<vector<ulli>> mult(const vector<vector<ulli>>& a, const vector<vector<ulli>>& b) {
        int n = a.size();
        int p = a[0].size();
        int m = b[0].size(); 
        vector<vector<ulli>> r(n, vector<ulli>(p, 0)); 
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
        vector<vector<ulli>> T{
            {1},
            {1},
            {1},
            {1},
            {1}
        };
        vector<vector<ulli>> B{
            vector<ulli>{0,1,1,0,1},
            {1,0,1,0,0},
            {0,1,0,1,0},
            {0,0,1,0,0},
            {0,0,1,1,0}
        };
        
        
        vector<vector<ulli>> R{
            vector<ulli>{1,0,0,0,0},
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