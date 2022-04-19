// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0; 
        int R = grid[0].size() - 1; 
        for (int i = 0; i < grid.size(); ++i) {
             
            int tmp = lowerBound(0, R, grid[i]);
            ans += grid[i].size() - tmp; 
            R = max<int>(min<int>(tmp, grid[i].size() - 1), 0);  
        }
        return ans; 
    }
    
    int lowerBound(int n, int R, vector<int>& data) {
        int ans = data.size(); 
        int L = 0; 
        
        int mid; 
        while(L <= R) {
            mid = L + (R - L)/2; 
            if (data[mid] >= n) {
                L = mid + 1; 
            } else if (data[mid] < n) {
                R = mid - 1; 
                ans = mid; 
                
            }
        }
        
        return ans; 
    } 
};