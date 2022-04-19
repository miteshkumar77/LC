// https://leetcode.com/problems/target-sum

class Solution {
public:
    int zero = 0; 
    int& get(int i, int j, vector<vector<int>>& v) {
        int offset = ((int)v[0].size() - 1)/2;
        if (j + offset < 0 || j + offset >= v[0].size()) {
            return zero;
        }
        return v[i][j + offset]; 
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size(); 
        int mag = accumulate(nums.begin(), nums.end(), 0); 
        int m = mag * 2; 
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); 
        get(0, 0, dp) = 1; 
        int num;
        for (int i = 1; i <= n; ++i) {
            num = nums[i - 1];
            for (int j = mag - mag - mag; j <= mag; ++j) {
                get(i, j, dp) = get(i - 1, j - num, dp) + get(i - 1, j + num, dp); 
            }
        }
        
        return get(n, S, dp); 
        
        
    }
};