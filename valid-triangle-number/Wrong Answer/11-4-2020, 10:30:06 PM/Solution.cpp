// https://leetcode.com/problems/valid-triangle-number

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            int k = i + 2;
            for (int j = i + 1; j < n; ++j) {
                while(k < n && nums[i] + nums[j] > nums[k]) {
                    ++k;
                }
                
                ans += k - j - 1;
            }    
        }
        
        return ans;
    }
};