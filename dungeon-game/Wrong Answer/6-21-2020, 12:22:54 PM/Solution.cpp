// https://leetcode.com/problems/dungeon-game

class Solution {
public:
    
    typedef array<int, 3> ti; // {row, col, cost}
    array<int, 3> dirs {0, 1, 0}; 
    int calculateMinimumHP(vector<vector<int>>& d) {
        
        
        int M = d.size(); int N = d[0].size(); 
        vector<vector<int> > min_sf (M, vector<int>(N, 0)); 
        vector<vector<int> > max_sf (M, vector<int>(N, 0)); 
        
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                
                if (i == 0 && j == 0) {
                    max_sf[i][j] = d[i][j]; 
                    min_sf[i][j] = d[i][j]; 
                } else {
                    
                    
                    if (i == 0) {
                        max_sf[i][j] = max_sf[i][j - 1] + d[i][j]; 
                        min_sf[i][j] = min(min_sf[i][j - 1], max_sf[i][j]); 
                    } else if (j == 0) {
                        max_sf[i][j] = max_sf[i - 1][j] + d[i][j]; 
                        min_sf[i][j] = min(min_sf[i - 1][j], max_sf[i][j]);
                    } else {
                        if (min_sf[i][j - 1] < min_sf[i - 1][j]) {
                            max_sf[i][j] = max_sf[i - 1][j] + d[i][j]; 
                            min_sf[i][j] = min(min_sf[i - 1][j], max_sf[i][j]); 
                        } else {
                            max_sf[i][j] = max_sf[i][j - 1] + d[i][j]; 
                            min_sf[i][j] = max_sf[i][j - 1] + d[i][j]; 
                            min_sf[i][j] = min(min_sf[i][j - 1], max_sf[i][j]); 
                        }
                    }
                }
            }
        }
        
//         for (int i = 0; i < M; ++i) {
//             for (int j = 0; j < N; ++j) {
//                 cout << setw(3) << max_sf[i][j] << ' '; 
//             }cout << endl; 
//         }
        
//         cout << endl << endl; 
//         for (int i = 0; i < M; ++i) {
//             for (int j = 0; j < N; ++j) {
//                 cout << setw(3) << min_sf[i][j] << ' '; 
//             }cout << endl; 
//         }
        
        int ans = min_sf.back().back(); 
        if (ans < 0) { return abs(ans) + 1; }
        else { return 1; }
    }
    
    
    
//     bool checkH(vector<vector<int> >& d, int t) {
//         int M = d.size(); 
//         int N = d[0].size(); 
//         if (d[0][0] + t <= 0) {
//             return false; 
//         } 
//         vector<vector<bool> > dsq (M, vector<bool>(N, false));
//         vector<vector<int> > dp (M, vector<int>(N, 0)); 
//         dp[0][0] = t;
//         for (int i = 0; i < M; ++i) {
//             for (int j = 0; j < N; ++j) {
//                 // cout << i << ' ' << j << endl; 
//                 if ((i != 0 || j != 0) && (i == 0 || dsq[i - 1][j]) && (j == 0 || dsq[i][j - 1])) {
//                     // cout << i << ' ' << j << endl; 
//                     dsq[i][j] = true; 
//                 } else {
                    
//                     vector<int> result; 
//                     if (i != 0 && !dsq[i - 1][j]) {
//                         result.push_back(dp[i - 1][j]); 
//                     }
                    
//                     if (j != 0 && !dsq[i][j - 1]) {
//                         result.push_back(dp[i][j - 1]); 
//                     }
                    
//                     if (result.size() == 0) {
//                         result.push_back(0); 
//                     }
//                     dp[i][j] += ((*max_element(result.begin(), result.end())) + d[i][j]); 
//                     if (dp[i][j] <= 0) {
//                         dsq[i][j] = true; 
//                     }
//                 } 
//             } 
//         }
//         return !dsq.back().back(); 
//     }
};