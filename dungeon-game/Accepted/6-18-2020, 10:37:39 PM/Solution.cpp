// https://leetcode.com/problems/dungeon-game

class Solution {
public:
    
    typedef array<int, 3> ti; // {row, col, cost}
    array<int, 3> dirs {0, 1, 0}; 
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int L = 1; 
        int R = 0; 
        int sum = 0; 
        
        if (dungeon.size() == 0 || dungeon[0].size() == 0) {
            return 0; 
        }
        for (int i = 0; i < dungeon[0].size(); ++i) {
            sum += dungeon[0][i];
            R = min(sum, R); 
        }
        
        
        for (int i = 1; i < dungeon.size(); ++i) {
            sum += dungeon[i].back(); 
            R = min(sum, R); 
        }
        
        R = 1 + abs(R); 
        
        cout << R << endl; 
        int ans = R; 
        while(L <= R) {
            int mid = L + (R - L)/2; 
            if (checkH(dungeon, mid)) {
                ans = mid; 
                R = mid - 1; 
            } else {
                L = mid + 1;  
            }
        }
        return ans; 
    }
    
    
    
    bool checkH(vector<vector<int> >& d, int t) {
        int M = d.size(); 
        int N = d[0].size(); 
        if (d[0][0] + t <= 0) {
            return false; 
        } 
        vector<vector<bool> > dsq (M, vector<bool>(N, false));
        vector<vector<int> > dp (M, vector<int>(N, 0)); 
        dp[0][0] = t;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                // cout << i << ' ' << j << endl; 
                if ((i != 0 || j != 0) && (i == 0 || dsq[i - 1][j]) && (j == 0 || dsq[i][j - 1])) {
                    // cout << i << ' ' << j << endl; 
                    dsq[i][j] = true; 
                } else {
                    
                    vector<int> result; 
                    if (i != 0 && !dsq[i - 1][j]) {
                        result.push_back(dp[i - 1][j]); 
                    }
                    
                    if (j != 0 && !dsq[i][j - 1]) {
                        result.push_back(dp[i][j - 1]); 
                    }
                    
                    if (result.size() == 0) {
                        result.push_back(0); 
                    }
                    dp[i][j] += ((*max_element(result.begin(), result.end())) + d[i][j]); 
                    if (dp[i][j] <= 0) {
                        dsq[i][j] = true; 
                    }
                } 
            } 
        }
        return !dsq.back().back(); 
    }
};