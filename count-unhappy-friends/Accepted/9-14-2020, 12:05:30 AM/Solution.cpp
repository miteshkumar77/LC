// https://leetcode.com/problems/count-unhappy-friends

class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<unordered_map<int,int>> prio(n); 
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                prio[i][preferences[i][j]] = j; 
            }
        }
        
        vector<int> pairmap(n, -1); 
        for (auto p : pairs) {
            pairmap[p[0]] = p[1]; 
            pairmap[p[1]] = p[0]; 
        }
        int ans = 0; 
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < prio[i][pairmap[i]]; ++j) {
                int player = preferences[i][j]; 
                if (prio[player][i] < prio[player][pairmap[player]]) {
                    ++ans; 
                    break; 
                }
            }
        }
        return ans; 
    }

};


//         vector<unordered_map<int,int>> prefidxs(preferences.size()); 
//         for (int i = 0; i < preferences.size(); ++i) {
//             for (int j = 0; j < preferences[i].size(); ++j) {
//                 prefidxs[i][preferences[i][j]] = j; 
//             }
//         }
        
        
//         vector<int> pairmap(preferences.size()); 
//         for (int i = 0; i < pairs.size(); ++i) {
//             pairmap[pairs[i][0]] = pairmap[pairs[i][1]]; 
//             pairmap[pairs[i][1]] = pairmap[pairs[i][0]]; 
//         }
        
//         int ans = 0;

        
//         for (int i = 0; i < pairmap.size(); ++i) {
//             for (int j = 0; j < prefidxs[i][pairmap[i]]; ++j) {
//                 int player = preferences[i][j]; 
                
//                 if (prefidxs[player][i] < prefidxs[player][pairmap[player]]) {
//                     ++ans; 
//                     cout << i << ' ' << player << endl; 
//                     break;
//                 }
//             }
//         }
//         return ans; 