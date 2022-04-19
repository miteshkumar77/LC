// https://leetcode.com/problems/minimum-falling-path-sum-ii

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        
        function<pair<int,int>(int)> get2MinIdxs = [&](int n) -> pair<int,int> {
            int min1 = INT_MAX; 
            int i1 = -1; 
            int min2 = INT_MAX; 
            int i2 = -1; 
            for (int i = 0; i < arr[n].size(); ++i) {
                if (arr[n][i] < min1) {
                    swap(min1, min2); 
                    swap(i1, i2); 
                    i1 = i; 
                    min1 = arr[n][i]; 
                } else if (arr[n][i] < min2) {
                    min2 = arr[n][i]; 
                    i2 = i; 
                }
            }
            return make_pair(i1, i2); 
        };
            
        for (int h = 1; h < arr.size(); ++h) {
            auto p = get2MinIdxs(h - 1); 
            for (int i = 0; i < arr[h].size(); ++i) {
                if (i == p.first) {
                    arr[h][i] += arr[h - 1][p.second]; 
                } else {
                    arr[h][i] += arr[h - 1][p.first]; 
                }
            }
        }
        
        return arr.back()[get2MinIdxs(arr.size() - 1).first]; 
    }
};