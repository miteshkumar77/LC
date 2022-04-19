// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        if (nums.size() == 0) {
            return 0; 
        }
        
        vector<int> piles(nums.size(), 0); 
        int R = 0;
        piles[0] = nums[0]; 

        for (int i = 1; i < nums.size(); ++i) {
            int pos = binSearch(piles, 0, R, nums[i]); 
            
            if (pos == -1) {
                piles[++R] = nums[i]; 
            } else {
                piles[pos] = nums[i]; 
            }
        }
        
        return R + 1; 
        
    }
    
    int binSearch(vector<int>& data, int L, int R, int& val) {
        int ans = -1; 
        
        
        while(L <= R) {
            int mid = L + (R - L)/2; 
            if (data[mid] >= val) {
                ans = mid; 
                R = mid - 1; 
            } else {
                L = mid + 1; 
            }
        }
        return ans; 
    }
    
    
};