// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0; 
        for (int i = 0; i < grid.size(); ++i) {
             ans += grid[i].size() - lowerBound(0, grid[i]); 
        }
        return ans; 
    }
    
    int lowerBound(int n, vector<int>& data) {
        int ans = data.size(); 
        int L = 0; 
        int R = data.size() - 1; 
        int mid; 
        while(L <= R) {
            mid = L + (R - L)/2; 
            if (data[mid] > n) {
                L = mid + 1; 
            } else if (data[mid] <= n) {
                R = mid - 1; 
                ans = mid; 
            }
        }
        
        return ans; 
    } 
};